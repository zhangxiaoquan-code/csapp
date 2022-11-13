#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>

#include "debug.h"

#define LOG_MODULE_LEN 32
#define LOG_MAN_LEN 1024

static int64_t g_loglevel = 0xf; //0011

char modules[][32] = {
    "cpu",
    "register",
    "test",
    "mem",
    "instruct"
};

char str_level[][32] = {
    "","fatal",
    "warning","",
    "info","","","",
    "debug"
};

int debug_printf(int64_t level, int module, const char *func, const char *file, int line, char *fmt, ...)
{
    if ((level & g_loglevel) == 0)
    {
        return 0;
    }

    int n;
    va_list args;
    struct timespec ts;
    char sprintf_buf[LOG_MAN_LEN] = {'0'};
 
	timespec_get(&ts, TIME_UTC);
	char time_buf[100];
	size_t rc = strftime(time_buf, sizeof time_buf, "%D %T", gmtime(&ts.tv_sec));   
	snprintf(time_buf + rc, sizeof time_buf - rc, ".%06ld UTC", ts.tv_nsec / 1000);

    va_start(args, fmt);
    n = vsnprintf(sprintf_buf, sizeof(sprintf_buf), fmt, args);
    printf("%s--%s-- :[module:%s][%s:%d-function:%s]: %s\n", time_buf, str_level[level],modules[module], file, line, func, sprintf_buf);
    va_end(args);

    if (level == FATAL_LOG_LEVEL)
    {
        exit(0);
    }

    return n;
}