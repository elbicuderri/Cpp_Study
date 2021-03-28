
CC=gcc
CFLAGS=-g -Wall

BIN=downloadexe

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $< -o $@ -lcurl


clean:
	$(RM) -rf $(BIN) *dSYM