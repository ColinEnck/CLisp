clisp: main.c token.c
	gcc -c main.c
	gcc -c token.c
	gcc main.o token.o -o clisp

clean:
	rm clisp