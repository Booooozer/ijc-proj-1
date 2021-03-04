//
// Created by tom on 3/4/21.
//

#include "bitset.h"
#include "eratosthenes.h"
#include <stdio.h>

#define ARRAYSIZE 200000000

int main() {
    bitset_create(p,ARRAYSIZE)

    Eratosthenes(p);

    int toRead = 0;
    unsigned long primes[10];

    for (unsigned long i = ARRAYSIZE - 1; toRead < 10; i--) {
        if (bitset_getbit(p,i) == 0) {
            primes[toRead] = i;
            toRead++;
        }
    }

    for (int i = 9; i >= 0 ; i--) {
        printf("%lu\n", primes[i]);
    }

    return 0;
}
