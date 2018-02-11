.PHONY : all clean

all : test.exe
clean :
	-rm -rf *~
	-rm -rf test.exe

test.exe : test.c json.c
	gcc -g -Wall -O2 -o $@ $^ -lm
