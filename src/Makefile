CC = gcc
CFLAGS = -g -O3 -Wall
OBJS = tokenizer.o history.o uimain.o

all: tokenizer

tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)

$(OBJS): history.h tokenizer.h

args: OBJS
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o tokenizer

run: tokenizer
	./tokenizer
