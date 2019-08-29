CC = g++
CCFLAGS = -Wall -g

all: program1

clean: clean1


###PROGRAM 1#######################
program1: prog1/main.o array.o Makefile
	${CC} ${CCFLAGS} -o program1 prog1/main.o array.o

clean1:
	rm -f program1 prog1/main.o array.o *.core

array.o: array.cpp array.h Makefile
	${CC} ${CCFLAGS} -c array.cpp
	
prog1/main.o: prog1/main.cpp array.h Makefile
	${CC} ${CCFLAGS} -o prog1/main.o -c prog1/main.cpp
	
