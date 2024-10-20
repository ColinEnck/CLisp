clisp: main.c token.c
	gcc -c -g main.c token.c
	gcc -g main.o token.o -o clisp

clean:
	rm clisp main.o token.o