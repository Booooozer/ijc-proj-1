//
// Created by tom on 3/3/21.
//
#include "bitset.h"
#include <math.h>

void Eratosthenes(bitset_t pole) {
    // 0 and 1 is not prime
    bitset_setbit(pole,0,1);

    bitset_setbit(pole,1,1);

    // loop from 2 to sqrt(N)
    unsigned long sizeBitset = bitset_size(pole);
    long double sqrtBitset = sqrt(sizeBitset);
    for (bitset_index_t i = 2; i < sqrtBitset; i++) {
        if (bitset_getbit(pole,i) == 0) {
            // mark all multiples of i as nonprime starting at i*i
            for (bitset_index_t j = i*i; j < sizeBitset; j += i) {
                bitset_setbit(pole,j,1);
            }
        }
    }
}
