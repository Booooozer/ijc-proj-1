CC = gcc
CFLAGS = -g -std=c11 -pedantic -Wall -Wextra -O2

# Compile everything
all: primes primes-i

# Run everything
run:
	./primes
	./primes-i

# Binaries
bitset.o: bitset.c
	$(CC) $(CFLAGS) -c bitset.c -o bitset.o

eratosthenes.o: eratosthenes.c bitset.o
	$(CC) $(CFLAGS) -c eratosthenes.c -o eratosthenes.o

primes.o: primes.c eratosthenes.c bitset.o
	$(CC) $(CFLAGS) -c primes.c -o primes.o

bitset-i.o: bitset.c
	$(CC) $(CFLAGS) -DUSE_INLINE -c bitset.c -o bitset-i.o

eratosthenes-i.o: eratosthenes.c bitset.o
	$(CC) $(CFLAGS) -DUSE_INLINE -c eratosthenes.c -o eratosthenes-i.o

primes-i.o: primes.c eratosthenes.c bitset.o
	$(CC) $(CFLAGS) -DUSE_INLINE -c primes.c -o primes-i.o

error.o: error.c
	$(CC) $(CFLAGS) -c error.c -o error.o


# Executables
primes: primes.o eratosthenes.o bitset.o error.o
	$(CC) $(CFLAGS) -lm primes.o eratosthenes.o bitset.o error.o -o primes

primes-i: primes-i.o eratosthenes-i.o bitset-i.o error.o
	$(CC) $(CFLAGS) -lm -DUSE_INLINE primes-i.o eratosthenes-i.o bitset-i.o error.o -o primes-i


zip:
	zip xmatus37-proj1.zip *.h *.c Makefile

clean:
	rm *.o primes primes-i
