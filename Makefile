CC = gcc -std=gnu99 -ggdb

test: test.o token.o lexer.o tmain.o pick_token.o fsm_helper.o assemble.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c -o $@ $^

clean:
	rm *.o
