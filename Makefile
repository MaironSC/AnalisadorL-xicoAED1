CC=gcc

CFLAGS=-Wall -Wextra -Werror -O0 -g -std=c11 -I.. 
LDLIBS=-lm

.PHONY: le pilha fila all clean

all:test
	./test

le:le.c
	$(CC) $(CFLAGS) -c le.c
	
pilha:le pilha.c
	$(CC) $(CFLAGS) -c pilha.c

fila:le fila.c
	$(CC) $(CFLAGS) -c fila.c

calc:fila pilha calc.c
	$(CC) $(CFLAGS) -c calc.c $(LDLIBS)
	
test:calc test.c
	$(CC) $(CFLAGS) -c test.c 
	$(CC) $(CFLAGS) -o test test.o calc.o fila.o pilha.o le.o $(LDLIBS)


	



# coloque outras dependencias aqui


test: calc.o test.c



clean:
	rm -f *.o test


