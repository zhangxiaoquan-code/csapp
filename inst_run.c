#include <stdio.h>

#include "cpu.h"
#include "inst.h"
#include "rsa.h"

int main(int argc, char **argv)
{
    if (argc < 2)
        return -1;

    read_inst(argv[1]);
    init_inst_set();
    rsa_cycle();
    match();

    return 0;
}