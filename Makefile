.PHONY : all clean

all : test.exe
clean :
	-rm -rf *~
	-rm -rf test.exe

test.exe : test.c json.c
	gcc -O3 -g -Wall -Wextra -Werror -o $@ $^ -lm
