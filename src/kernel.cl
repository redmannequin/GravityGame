#define SIZE 128

__kernel void fixedPoint(__global float2* input, __global float2* output, const unsigned int count) {

    int gid = get_global_id(0);
    int lid = get_local_id(0);
    
    int gs = get_global_size(0);
    int ls = get_local_size(0);
    int ws = gs/ls;

    __local float2 pblock[SIZE];
    float2 acc = 0;
    float2 curr = input[gid];

    for (int i=0; i < ws; ++i) {
        int k = (i*ls)+lid;
        pblock[lid] = input[k];
        barrier(CLK_LOCAL_MEM_FENCE);
        for (int j=0; j < ls; ++j) {
            float2 prev = acc;
            float2 dist = pblock[j]-curr;
            float invr = rsqrt(dist.s0*dist.s0 + dist.s1*dist.s1);
            float force = invr*invr*invr;
            float2 temp = dist*(force*1.f);
            if (temp.s0 != temp.s0 || temp.s1 != temp.s1) temp = 0;
            acc =  prev+temp;
        }
        barrier(CLK_LOCAL_MEM_FENCE);
    }

    output[gid].s0 = acc.s0;
    output[gid].s1 = acc.s1;
} 