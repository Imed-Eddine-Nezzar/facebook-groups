ERR = $(shell which clang++ >/dev/null; echo $$?)
ifeq "$(ERR)" "0"
	    CC = clang++
	else
	    CC = g++
	endif
CFLAGS=-g -Werror -Wall
TARGET=main
DEP=dictfunc.h
OUT=dict

all: main.cpp
	$(CC) $(CFLAGS) main.cpp -o dict.out

clean:
	rm *.out

