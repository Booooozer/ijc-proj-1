###############################
# Makefile
# Řešení IJC-DU1
# Autor: Tomáš Matuš, FIT
# Login: xmatus37
# Datum: 15.3.2021
###############################


# Compiler and flags
CC = gcc
CFLAGS = -g -std=c11 -pedantic -Wall -Wextra -O2

# Compile everything
all: primes primes-i steg-decode

# Compile and run primes
run: primes primes-i
	./primes
	./primes-i


# Binaries
bitset.o: bitset.c bitset.h
	$(CC) $(CFLAGS) -c bitset.c -o bitset.o

eratosthenes.o: eratosthenes.c eratosthenes.h
	$(CC) $(CFLAGS) -c eratosthenes.c -o eratosthenes.o

primes.o: primes.c
	$(CC) $(CFLAGS) -c primes.c -o primes.o

bitset-i.o: bitset.c bitset.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c bitset.c -o bitset-i.o

eratosthenes-i.o: eratosthenes.c eratosthenes.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c eratosthenes.c -o eratosthenes-i.o

primes-i.o: primes.c
	$(CC) $(CFLAGS) -DUSE_INLINE -c primes.c -o primes-i.o

error.o: error.c error.h
	$(CC) $(CFLAGS) -c error.c -o error.o

ppm.o: ppm.c ppm.h
	$(CC) $(CFLAGS) -c ppm.c -o ppm.o


# Executables
primes: primes.o eratosthenes.o bitset.o error.o
	$(CC) $(CFLAGS) -lm primes.o eratosthenes.o bitset.o error.o -o primes

primes-i: primes-i.o eratosthenes-i.o bitset-i.o error.o
	$(CC) $(CFLAGS) -lm -DUSE_INLINE primes-i.o eratosthenes-i.o bitset-i.o error.o -o primes-i

steg-decode: steg-decode.c ppm.o eratosthenes.o bitset.o error.o
	$(CC) $(CFLAGS) -lm steg-decode.c ppm.o eratosthenes.o bitset.o error.o -o steg-decode


# Misc
zip:
	zip xmatus37-proj1.zip *.h *.c Makefile

clean:
	rm *.o primes primes-i steg-decode
