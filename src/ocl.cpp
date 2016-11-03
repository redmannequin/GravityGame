#include "ocl.h"

#include <sstream>
#include <fstream>
#include <cstring>

#include <iostream>

OCL::OCL() {
  err    = 0;
  global = 0;
  local  = 0;

  cpPlatform = 0;
  device_id  = 0;
  context    = 0;
  commands   = 0;
  program    = 0;
  kernel     = 0;

  input  = 0;
  output = 0;
  count  = 0;
  size   = 0;
}

int OCL::init(size_t dataSize, unsigned int dataCount, char * filename) {
  size  = dataSize;
  count = dataCount;
  global = count;

  err = clGetPlatformIDs(1, &cpPlatform, NULL);
  if (err != CL_SUCCESS) return -1;

  err = clGetDeviceIDs(cpPlatform, CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);
  if (err != CL_SUCCESS) return -2;

  context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
  if (!context) return -3;

  commands = clCreateCommandQueue(context, device_id, 0, &err);
  if (!commands) return -4;

  std::ifstream file;
  file.open(filename);
  std::ostringstream ss;
  ss << file.rdbuf();
  std::string s = ss.str();
  file.close();

  KernelSource = new char[s.length()+1];
  strcpy(KernelSource, s.c_str());

  program = clCreateProgramWithSource(context, 1, (const char **) &KernelSource, NULL, &err);
  if (!program) return -5;

  err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
  if (err != CL_SUCCESS) {
    size_t len;
    char buffer[2048];
    std::cout << "Error: Failed to build program executable!" << std::endl;
    clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
    std::cout << "[ERROR]: " << buffer << std::endl;
    return -6;
  }

  kernel = clCreateKernel(program, "fixedPoint", &err);
  if (!kernel || err != CL_SUCCESS) return -7;

  input  = clCreateBuffer(context, CL_MEM_READ_ONLY, size*count, NULL, NULL);
  output = clCreateBuffer(context, CL_MEM_WRITE_ONLY, size*count, NULL, NULL);
  if (!input || !output) return -8;
  
  return 1;  
}

int OCL::run(void * data, void * results) {
  err = clEnqueueWriteBuffer(commands, input, CL_TRUE, 0, size*count, (void *)data, 0, NULL, NULL);
  if (err != CL_SUCCESS) return -9;
  
  //err = clGetKernelWorkGroupInfo(kernel, device_id, CL_KERNEL_WORK_GROUP_SIZE, sizeof(local), &local, NULL);
  //if (err != CL_SUCCESS) return -11;

  local = 64;

  err  = 0;
  err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &input);
  err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &output);
  err |= clSetKernelArg(kernel, 2, sizeof(int), &global);
  if (err != CL_SUCCESS) return -10;

  err = clEnqueueNDRangeKernel(commands, kernel, 1, NULL, &global, &local, 0, NULL, NULL);
  if (err) return -12;

  clFinish(commands);

  err = clEnqueueReadBuffer(commands, output, CL_TRUE, 0, size*count, (void *)results, 0, NULL, NULL );
  if (err != CL_SUCCESS) return -13;

  return 1;
}

void OCL::release() {
  delete[] KernelSource;
  clReleaseMemObject(input);
  clReleaseMemObject(output);
  clReleaseProgram(program);
  clReleaseKernel(kernel);
  clReleaseCommandQueue(commands);
  clReleaseContext(context);
}