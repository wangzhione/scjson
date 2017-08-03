test.exe : test.c scjson.c tstr.c
	gcc -g -Wall -O2 -o $@ $^ -lm
