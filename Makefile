.PHONY: matrix debug

matrix: matrix.c luadebug.c
	gcc -Wall -o matrix matrix.c luadebug.c -llua

debug: matrix.c luadebug.c
	gcc -Wall -DDEBUG -o matrix matrix.c luadebug.c -llua
