/*
 * bitset.h
 * Řešení IJC-DU1
 * Autor: Tomáš Matuš, FIT
 * Login: xmatus37
 * Datum: 15.3.2021
 * Přeloženo: gcc 10.2.0
 */

#include "error.h"
#include <limits.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#ifndef BITSET_H
#define BITSET_H

#define BITSET_MAX 200000000    // 200 million

typedef unsigned long bitset_t[];

typedef unsigned long bitset_index_t;

#define UL_SIZE (sizeof(unsigned long) * CHAR_BIT)

// creates static array on stack
#define bitset_create(jmeno_pole,velikost)                                                                    \
        /* (how many ULs are needed) + (1 extra when the number of bits
         * is not dividable by UL_SIZE) + 1 for array[0] where the size of bit array is saved */              \
        unsigned long jmeno_pole [((velikost / UL_SIZE) + ((velikost % UL_SIZE) ? 1 : 0) + 1)] = {velikost,}; \
        _Static_assert(velikost > 0, "Velikost pole musi byt vetsi nez 0");

// allocates array on heap
#define bitset_alloc(jmeno_pole,velikost)                               \
        assert(velikost > 0);                                           \
        assert(velikost <= BITSET_MAX);                                 \
        unsigned long *jmeno_pole = calloc(((velikost / UL_SIZE) +      \
        ((velikost % UL_SIZE) ? 1 : 0) + 1), sizeof(unsigned long));    \
        if(jmeno_pole == NULL) {                                        \
            fprintf(stderr, "bitset_alloc: Chyba alokace pameti");      \
            return 1;                                                   \
        }                                                               \
        jmeno_pole[0] = velikost;

#define bitset_free(jmeno_pole) \
    free(jmeno_pole);           \
    jmeno_pole = NULL;


#ifndef USE_INLINE

// macros

// returns the size of bit array
#define bitset_size(jmeno_pole) (jmeno_pole[0])

// sets selected bit
/* ternary operator inside of a ternary operator
 * first one is used to check if index is out of bounds
 * second one is used to set bit to 0 or 1
 */
#define bitset_setbit(jmeno_pole,index,vyraz) ((index >= bitset_size(jmeno_pole)) ? \
         /* operator "," so this part of ternary operator has something to return (exit before 1 is returned) */   \
        (error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", index, bitset_size(jmeno_pole))), 1 :  \
        ((vyraz == 1) ?                                                           \
        (jmeno_pole[(index / UL_SIZE) + 1] |= (1UL << ((index) % UL_SIZE))) :   \
        (jmeno_pole[(index / UL_SIZE) + 1] &= (0UL << ((index) % UL_SIZE)))))

// returns value of bit
#define bitset_getbit(jmeno_pole,index) ((index >= bitset_size(jmeno_pole)) ?                                 \
        /* operator "," so this part of ternary operator has something to return (exit before 1 is returned) */     \
        (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", index, bitset_size(jmeno_pole))), 1 : \
        (jmeno_pole[(index / UL_SIZE) + 1] & (1UL << ((index) % UL_SIZE))))


#else

// inline functions

    inline unsigned long bitset_size(bitset_t jmeno_pole) {
        return jmeno_pole[0];
    }

    inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, char vyraz) {
        if(index > bitset_size(jmeno_pole)){
            error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", index, bitset_size(jmeno_pole));
        }

        (vyraz == 1) ? (jmeno_pole[(index / UL_SIZE) + 1] |= (1UL << ((index) % UL_SIZE))) : \
        (jmeno_pole[(index / UL_SIZE) + 1] &= ~(1UL << ((index) % UL_SIZE)));
        return;
    }

    inline unsigned long bitset_getbit(bitset_t jmeno_pole, bitset_index_t index) {
        if(index > bitset_size(jmeno_pole)){
            error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", index, bitset_size(jmeno_pole));
        }

        return (jmeno_pole[(index / UL_SIZE) + 1] & (1UL << ((index) % UL_SIZE)));
    }

#endif //USE_INLINE

#endif //BITSET_H
