CC = gcc
CFLAGS = -Wall -O2 -Iinclude
SRC = src/main.c src/actions.c src/utils.c
OUT = rebootx

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

install:
	@sudo mv $(OUT) /usr/local/bin/
	@echo "Installed to /usr/local/bin/rebootx"

clean:
	rm -f $(OUT)
