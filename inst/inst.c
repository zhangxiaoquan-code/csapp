#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "inst.h"

inst_t inst[100];

char str_instl[OP_MAX][6] = 
{
    "mov","add","sub", "pop", "push", "call", "ret", "cmp", "jne", "je", "jump", "inc", "leave","nopw"
};

operator_type get_inst(operator_t **src, operator_t **dst)
{
    static int index = 0;
    //memcpy(src, &inst[index].src, sizeof(operator_t));
    //memcpy(dst, &inst[index].dst, sizeof(operator_t));
    *src = &inst[index].src;
    *dst = &inst[index].dst;

    return inst[index++].op;
}

static int para_operate(char *str_inst, int inst_count)
{
    if (str_inst[0] == 'm')
        inst[inst_count].op = MOV;
    else if (str_inst[0] == 'a')
        inst[inst_count].op = ADD;
    else if (str_inst[0] == 's')
        inst[inst_count].op = SUB;
    else if (str_inst[0] == 'i')
        inst[inst_count].op = INC;
    else if (str_inst[0] == 'r')
        inst[inst_count].op = RET;
    else if (str_inst[0] == 'l')
        inst[inst_count].op = LEAVE;
    else if (str_inst[0] == 'c')
    {
        if (str_inst[1] == 'a')
            inst[inst_count].op = CALL;
        else
            inst[inst_count].op = CMP;
    }
     else if (str_inst[0] == 'j')
    {
        if (str_inst[1] == 'n')
            inst[inst_count].op = JNE;
        else
            inst[inst_count].op = JE;
    }
     else if (str_inst[0] == 'p')
    {
        if (str_inst[1] == 'o')
            inst[inst_count].op = POP;
        else
            inst[inst_count].op = PUSH;
    }

    return inst[inst_count].op;     
}

static int para_operate_obj(char *str_inst, int *inst_count)
{
    int inst_index = *inst_count;
    switch (inst[inst_index].op)
    {
        case MOV:
            /* code */
            break;
        case ADD:
            inst[inst_index].src.type = REGISTER;
            inst[inst_index].dst.type = REGISTER;
            //inst[inst_count].src.op.reg=cpu[0].cpu_reg.rax;
            //inst[inst_count].dst.op.reg=cpu[0].cpu_reg.rax;
            break;
        case SUB:
            /* code */
            break;
        case POP:
            inst[inst_index].src.type = EMPTY;
            inst[inst_index].dst.type = REGISTER;
            //inst[inst_count].dst.op.reg = reg;
            break;
        case PUSH:
            inst[inst_index].src.type = REGISTER;
            inst[inst_index].dst.type = EMPTY;
            //inst[inst_count].src.op.reg = reg;
            
            break;
        case CALL:
            /* code */
            break;
        case RET:
            /* code */
            break;
        case CMP:
            /* code */
            break;
        case JNE:
            /* code */
            break;
        case JE:
            /* code */
            break;
        case JUMP:
            /* code */
            break;
        case INC:
            /* code */
            break;
        case LEAVE:
            /* code */
            break;
        
        default:
            goto INVALID_INST;
            break;
    }

    (*inst_count) ++;

INVALID_INST:
    return 0;
}

static int para_inst(char *buf, int count)
{
    char *str_inst = NULL;
    static int inst_count = 0;

    for (int i = 0 ; i < OP_MAX; i++)
    {
        str_inst = strstr(buf, str_instl[i]);
        if (str_inst == NULL)
            continue;
        
        reg_info("%d %s", inst_count, str_inst);
        
        para_operate(str_inst, inst_count);
        para_operate_obj(str_inst, &inst_count);
    }
    return 0;
}

static int readline(int fd,char* buff)
{
    int rl = -1;
    char c;
    long count = 0;

    if(fd < 0)
    {
        reg_debug("%s","open file error");
        exit(0);
    }

    while((rl = read(fd, &c, 1)) > 0)
    {
        if(c == '\n')
        {
            break;
        }
        buff[count++] = c;
        if (c == EOF)
            return -1;

    }
    if (count == 0)
        return -1;

    buff[count]='\0';

    return count;
}

int read_inst(char *inst_file)
{
    int fd = -1;
    int line_count = -1;
    char buf[1024];

    if ((fd = open(inst_file, O_RDONLY)) == -1)
    {
        reg_fatal("file %s open failed", inst_file);
    }

    while((line_count = readline(fd, buf)) != -1)
    {
        if (line_count == -1)
        {
            break;
        }
        if ((buf[0] == '#') || (strlen(buf) == 0))
        {
            continue;
        }

        para_inst(buf, line_count);
    }
    

    return 0;
}

int match(void)
{
    return 0;
}