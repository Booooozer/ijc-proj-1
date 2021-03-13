//
// Created by tom on 3/4/21.
//

#include "bitset.h"
#include "eratosthenes.h"
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 200000000    // 200 million

int main() {
    clock_t start = clock();

    bitset_create(p, ARRAY_SIZE)
    Eratosthenes(p);

    int toRead = 0;
    unsigned long primes[10];

    for (bitset_index_t i = ARRAY_SIZE - 1; toRead < 10; i--) {
        if (bitset_getbit(p,i) == 0) {
            primes[toRead] = i;
            toRead++;
        }
    }

    for (int i = 9; i >= 0 ; i--) {
        printf("%lu\n", primes[i]);
    }

    fprintf(stderr, "Time=%.3g\n", (double)(clock() - start) / CLOCKS_PER_SEC);

    return 0;
}
