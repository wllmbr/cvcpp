CC = g++
NAME = cppTest

#Auto file grabbing
INIT = main.cpp
FILES = $(wildcard *.cpp)
HEADERS = $(wildcard *.hpp)
LIBS = $(filter-out $(INIT), $(FILES))
OBJS = $(patsubst %.cpp, $(BLD)/%.o, $(LIBS))
BLD = bld

WARN = -Wall
OPT = -O3
LINK = -pthread

OBJ_CMD = objdump
OBJ_FLAGS = --disassemble-all --source --line-numbers

EXE = $(NAME).exe
DIS = $(NAME).asm


all: $(EXE) $(DIS)

$(DIS): $(EXE)
	$(OBJ_CMD) $(OBJ_FLAGS) $^ >> $@

$(EXE): $(INIT) $(OBJS) $(HEADERS)
	$(CC) $(WARN) $(OPT) -o $@ $^

$(BLD)/%.o: %.cpp
	$(CC) $(WARN) $(OPT) -o $@ -c $^

$(BLD)/%.o: %.cpp %.hpp
	$(CC) $(WARN) $(OPT) -o $@ -c $^

.PHONY: all clean remake

clean:
	rm -rf $(BLD)/* *.o *.exe *.asm

remake:
	make clean; make