# Makefile of float-wrapper

CC=g++
CFLAGS=-O0 -Wall -Wextra -std=c++11

SRC=./src/
TEST_SRC=./test/
TEST_MAIN=$(TEST_SRC)main.cpp
TEST_EXE=float-wrapper

FLOAT_HEADER=$(SRC)Float.hpp
FLOAT_SRC=$(SRC)Float.cpp

FLOAT_OBJ=Float.o
TEST_OBJ=main.o
OBJS=$(FLOAT_OBJ) $(TEST_OBJ)

all: test

test: $(TEST_EXE)
	@echo $(TEST_EXE)" generated. "


$(TEST_EXE) : $(OBJS)
	@echo $@" - Compiling..."
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)
	@echo $@" - done."

$(FLOAT_OBJ) : $(FLOAT_SRC) $(FLOAT_HEADER)
	@echo $<" -> "$@
	$(CC) -c $(CFLAGS) -o $@ $< $(LFLAGS)
	@echo $<" -> "$@" done."


$(TEST_OBJ) : $(TEST_MAIN) $(FLOAT_HEADER)
	@echo $<" -> "$@
	$(CC) -c $(CFLAGS) -o $@ $< $(LFLAGS)
	@echo $<" -> "$@" done."

mrproper:
	rm -f $(TEST_EXE) $(OBJS)
