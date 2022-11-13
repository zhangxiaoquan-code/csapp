#ifndef _DEBUG_H
#define _DEBUG_H

#include <stdint.h>

//support model define
#define CPU_LOG_MODUEL        (0x1 << 0)
#define REGISTER_LOG_MODUEL   (0x1 << 1)
#define TEST_LOG_MODUEL       (0x1 << 2)
#define MEN_LOG_MODUEL        (0x1 << 3)


#define CPU_MODUEL        0
#define REGISTER_MODUEL   1
#define TEST_MODUEL       2
#define MEN_MODUEL        3
#define INST_MODUEL       4

//support level define
#define FATAL_LOG_LEVEL        (0x1 << 0)  //0001 -1
#define WARNING_LOG_LEVEL      (0x1 << 1) //0010  -2
#define INFO_LOG_LEVEL         (0x1 << 2) //0100  -4
#define DEBUG_LOG_LEVEL        (0x1 << 3) //1000  -8

int debug_printf(int64_t level, int module, const char *func, const char *file, int line, char *fmt, ...);

#endif // !_DEBUG_H