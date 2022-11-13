#ifndef REGISTER_H
#define REGISTER_H

#include "debug.h"

#define reg_debug(fmt, ...) \
    debug_printf(DEBUG_LOG_LEVEL, INST_MODUEL, __func__,__FILE__, __LINE__, fmt, __VA_ARGS__)
#define reg_info(fmt, ...) \
    debug_printf(INFO_LOG_LEVEL, INST_MODUEL, __func__,__FILE__, __LINE__, fmt, __VA_ARGS__)
#define reg_warning(fmt, ...) \
    debug_printf(WARNING_LOG_LEVEL, INST_MODUEL, __func__,__FILE__, __LINE__, fmt, __VA_ARGS__)
#define reg_fatal(fmt, ...) \
    debug_printf(FATAL_LOG_LEVEL, INST_MODUEL, __func__,__FILE__, __LINE__, fmt, __VA_ARGS__)

#define MAX_INSTRUCT_LEGTH 100

typedef enum
{
    MOV,
    ADD,
    SUB,
    POP,
    PUSH,
    CALL,
    RET,
    CMP,
    JNE,
    JE,
    JUMP,
    INC,
    LEAVE,
    NOP,
    OP_MAX
}operator_type;

typedef enum
{
    EMPTY,
    IMME,
    REGISTER,
    OFFSET,
    SCALE
}op_t;

typedef struct
{
    uint64_t reg;
    uint64_t imme;
    uint64_t sacle;
}opt;

typedef struct
{
    op_t type;
    opt  op;
}operator_t;

typedef struct inst
{
    operator_type op;
    operator_t  src;
    operator_t  dst;
}inst_t;

int match(void);
int read_inst(char *inst_file);
operator_type get_inst(operator_t *src, operator_t *dst);

#endif // !REGISTER_H