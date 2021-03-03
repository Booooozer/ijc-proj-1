CC = gcc
CFLAGS = -g -std=c11 -pedantic -Wall -Wextra

tom:
	$(CC) $(CFLAGS) main.c -o main

tom-i:
	$(CC) $(CFLAGS) -DUSE_INLINE main.c -o main
