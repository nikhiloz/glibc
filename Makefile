CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lpthread -lm

SRC = glibc_demo.c glibc_demo2.c
BIN = glibc_demo glibc_demo2

all: $(BIN)

glibc_demo: glibc_demo.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

glibc_demo2: glibc_demo2.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(BIN)

.PHONY: all clean