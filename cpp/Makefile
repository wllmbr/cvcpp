# Multi-target Makefile

#Linux Compiler Settings
LINUX = linux_matrix_test_cpp.exe
LINUX_CC = g++
LINUX_OBJ = objdump
LINUX_MAIN = linux_init.cpp
LINUX_NAME = linux_matrix_test
LINUX_CFLAGS = $(OPT) $(WARN) 

#RTEMS Compiler Settings
RTEMS_LOC = /rtems/rtems-toolchain/bin
RTEMS = rtems_matrix_test.exe
RTEMS_CC = $(RTEMS_LOC)/arm-rtems5-g++
RTEMS_OBJ = $(RTEMS_LOC)/arm-rtems5-objdump 
RTEMS_MAIN = rtems_init.cpp
RTEMS_CFLAGS = $(LINUX_CFLAGS) $(TARGET_SETTINGS)
TARGET_SETTINGS = -B/rtems/rtems-board-support/5/arm-rtems5/raspberrypi/lib -specs bsp_specs -qrtems -mcpu=arm1176jzf-s
RTEMS_IMG_CMD = $(RTEMS_LOC)/arm-rtems5-objcopy -Obinary
RTEMS_IMG = kernel_cpp.img


#Auto file grabbing
INIT = $(LINUX_MAIN) $(RTEMS_MAIN)
FILES = $(wildcard *.cpp)
HEADERS = $(wildcard *.hpp)
OBJS = $(filter-out $(INIT), $(FILES))
EXES = $(patsubst %.cpp, %.exe, $(INIT))
SYMB = $(patsubst %.cpp, %.asm, $(INIT))

WARN = -Wall
OPT = -O3 

OBJ_FLAGS = --disassemble-all --source --line-numbers

EXE = $(NAME).exe
DIS = $(NAME).asm

all: $(RTEMS) $(LINUX) $(RTEMS_IMG)

$(RTEMS_IMG): $(RTEMS)
	$(RTEMS_IMG_CMD) $^ $@

$(RTEMS): $(RTEMS_MAIN) $(OBJS)
	$(RTEMS_CC) $(RTEMS_CFLAGS) -o $@ $^

$(LINUX): $(LINUX_MAIN) $(OBJS)
	$(LINUX_CC) $(LINUX_CFLAGS) -o $@ $^


.PHONY: all clean remake 

clean:
	rm -rf *.o *.exe *.asm *.img

remake:
	make clean; make