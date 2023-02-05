TARGET=inst_run
SRC=inst_run.c ./common/debug.c ./common/common.c ./inst/cpu.c ./inst/inst.c ./inst/rsa.c
CC=gcc
CFLAG=-g -Wall -ggdb
OBJDUMP=$(TOOLPREFIX)objdump

.PHONY:all
$(TARGET):$(SRC)
	$(CC) $(CFLAG) -I ./include -o $@ $^
	$(OBJDUMP) -D $(TARGET) > $(TARGET).obj

run:
	./$(TARGET) test.txt

clean:
	rm -rf $(TARGET)
	rm -rf *.o
