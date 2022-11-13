#include "rsa.h"
#include "cpu.h"
#include "inst.h"

#include <stddef.h>

typedef void (*inst_hander_t)(operator_t *, operator_t *, cpu_t *);

typedef struct inst_handle
{
    operator_type opt;
    inst_hander_t handler;
}inst_handle_t;

// update the rip pointer to the next instruction sequentially
static inline void increan_pc(cpu_t *cpu)
{
    cpu->cpu_pc.rip = cpu->cpu_pc.rip + sizeof(char) * MAX_INSTRUCT_LEGTH;
}

void mov_handler(operator_t *src, operator_t *dst, cpu_t *cpu)
{
    increan_pc(cpu);
}

void push_handler(operator_t *src, operator_t *dst, cpu_t *cpu)
{
    increan_pc(cpu);
}

void pop_handler(operator_t *src, operator_t *dst, cpu_t *cpu)
{
    increan_pc(cpu);
}

void add_handler(operator_t *src, operator_t *dst, cpu_t *cpu)
{
    increan_pc(cpu);
}

void sub_handler(operator_t *src, operator_t *dst, cpu_t *cpu)
{
    increan_pc(cpu);
}

void call_handler(operator_t *src, operator_t *dst, cpu_t *cpu)
{
    increan_pc(cpu);
}

void ret_handler(operator_t *src, operator_t *dst, cpu_t *cpu)
{
    increan_pc(cpu);
}

void nop_handler(operator_t *src, operator_t *dst, cpu_t *cpu)
{
    increan_pc(cpu);
}

inst_handle_t instruct_handler[OP_MAX] = {
    {MOV, mov_handler},
    {ADD, add_handler},
    {SUB, sub_handler},
    {POP, pop_handler},
    {PUSH, push_handler},
    {CALL, call_handler},
    {RET, ret_handler},
    {NOP, nop_handler},
};

void init_inst_set(void)
{
    return;
}

void rsa_cycle(void)
{
    operator_t src;
    operator_t dst;
    operator_type inst_index;

    for(int i = 0; i < 100; i++)
    {
        /// read instruct 
        inst_index = get_inst(&src, &dst);
        if (instruct_handler[inst_index].handler != NULL)
            instruct_handler[inst_index].handler(&src,&dst,&cpu[0]);
    }
    return;
}