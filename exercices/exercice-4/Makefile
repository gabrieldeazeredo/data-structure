MAIN=main.c
BINARY=exec
UTIL=bignumber.c util.c

all:
	gcc -Wall -Werror -g $(MAIN) $(UTIL) -o $(BINARY) -lm

run:
	./$(BINARY)

debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

zip:
	zip entrega.zip *.c *.h Makefile
clear:
	@rm *.o

