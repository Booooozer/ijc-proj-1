CC = gcc
CFLAGS = -g -std=c11 -pedantic -Wall -Wextra -O0


primes: primes.o eratosthenes.o
	$(CC) $(CFLAGS) primes.o eratosthenes.o -o primes -lm

primes-i: primes-i.o eratosthenes.o
	$(CC) $(CFLAGS) -DUSE_INLINE primes-i.o eratosthenes.o -o primes-i -lm





eratosthenes.o: eratosthenes.c
	$(CC) $(CFLAFS) -c eratosthenes.c

primes.o: primes.c eratosthenes.c
	$(CC) $(CFLAGS) -c primes.c

primes-i.o: primes.c eratosthenes.c
	$(CC) $(CFLAGS) -c primes.c -DUSE_INLINE


clean:
	rm *.o primes primes-i
