CC = gcc
CFLAGS = -g -std=c11 -pedantic -Wall -Wextra -O2


all: primes primes-i

run: primes primes-i
	./primes
	./primes-i


bitset.o: bitset.c
	$(CC) $(CFLAGS) -c bitset.c -o bitset.o

eratosthenes.o: eratosthenes.c bitset.o
	$(CC) $(CFLAGS) -c eratosthenes.c -o eratosthenes.o

primes.o: primes.c eratosthenes.c bitset.o
	$(CC) $(CFLAGS) -c primes.c -o primes.o

primes-i.o: primes.c eratosthenes.c bitset.o
	$(CC) $(CFLAGS) -c primes.c -DUSE_INLINE -o primes-i.o



primes: primes.o eratosthenes.o
	$(CC) $(CFLAGS) primes.o eratosthenes.o -o primes -lm

primes-i: primes-i.o eratosthenes.o
	$(CC) $(CFLAGS) -DUSE_INLINE primes-i.o eratosthenes.o -o primes-i -lm


zip:
	zip xmatus37-proj1.zip *.h *.c Makefile

clean:
	rm *.o primes primes-i
