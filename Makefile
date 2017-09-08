.PHONY : all clean

all : test.exe
clean :
	-rm -rf *~
	-rm -rf test.exe

test.exe : test.c scjson.c tstr.c
	gcc -g -Wall -O2 -o $@ $^ -lm
