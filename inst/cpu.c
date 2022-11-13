#include <stddef.h>

#include "cpu.h"

//4 core cpu
cpu_t cpu[CPU_NUM];

cpu_t *getCpuRegister(uint8_t cpu_index)
{
    if (cpu_index >= CPU_NUM)
    {
        return NULL;
    }
    return &cpu[cpu_index];
}


