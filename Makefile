clisp: main.c token.c
	gcc -c -g main.c mystring.c token.c stack.c
	gcc -g main.o mystring.o token.o stack.o -o clisp

clean:
	rm clisp main.o mystring.o token.o