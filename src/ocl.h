#ifndef OCL_H
#define OCL_H

#include <CL/cl.h>

class OCL {
  public:
    OCL();

    int init(size_t dsize, unsigned int dcount, char * filename);
    int run(void * data, void * results);
    void release();

  private:
    cl_int err;     // error code
    size_t global;  // global size
    size_t local;   // local size
   
    cl_platform_id   cpPlatform; // platform
    cl_device_id     device_id;  // device id
    cl_context       context;    // context
    cl_command_queue commands;   // command queue
    cl_program       program;    // program
    cl_kernel        kernel;     // kernel

    cl_mem input;         // device memory 
    cl_mem output;        // device memory
    unsigned int count;   // data size
    size_t size;          // size of data type 

    char *KernelSource;
};

#endif