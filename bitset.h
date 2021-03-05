//
// Created by tom on 3/1/21.
//
#include <limits.h>
#include <stdlib.h>
#include <assert.h>

#ifndef BITSET_H
#define BITSET_H

typedef unsigned long bitset_t[];

typedef unsigned long bitset_index_t;

#define UL_SIZE (sizeof(unsigned long) * CHAR_BIT)

// creates static array on stack
#define bitset_create(jmeno_pole,velikost)_Static_assert(velikost > 0, "Velikost pole musi byt vetsi nez 0"); \
        /* (how many ULs are needed) + (1 extra when the number of bits
         * is not dividable by UL_SIZE) + 1 for array[0] where the size of bit array is saved */              \
        unsigned long jmeno_pole [((velikost / UL_SIZE) + ((velikost % UL_SIZE) ? 1 : 0) + 1)] = {velikost};

// allocates array on heap
#define bitset_alloc(jmeno_pole,velikost)                               \
        assert(velikost > 0);                                           \
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
#define bitset_size(jmeno_pole)jmeno_pole[0]

// sets selected bit
/* to set 1: (index where selected bit is + 1 as array[0] == size)
 * then left shift 1 to selected bit and use bitwise OR
 * to set 0: use bitwise AND to set selected bit to 0
 */
#define bitset_setbit(jmeno_pole,index,vyraz) (vyraz == 1) ?                    \
        (jmeno_pole[(index / UL_SIZE) + 1] |= (1UL << ((index) % UL_SIZE))) :   \
        (jmeno_pole[(index / UL_SIZE) + 1] &= (0UL << ((index) % UL_SIZE)))


#define bitset_getbit(jmeno_pole,index) (jmeno_pole[(index / UL_SIZE) + 1] & (1UL << ((index) % UL_SIZE)))

#else

// inline functions

    static inline unsigned long bitset_size(bitset_t jmeno_pole) {
        return jmeno_pole[0];
    }

    static inline void bitset_setbit(bitset_t jmeno_pole, unsigned long index, char vyraz) {
        (vyraz == 1) ? (jmeno_pole[(index / UL_SIZE) + 1] |= (1UL << ((index) % UL_SIZE))) : \
        (jmeno_pole[(index / UL_SIZE) + 1] &= ~(1UL << ((index) % UL_SIZE)));
        return;
    }

    static inline unsigned long bitset_getbit(bitset_t jmeno_pole, unsigned long index) {
        return (jmeno_pole[(index / UL_SIZE) + 1] & (1UL << ((index) % UL_SIZE)));
    }


#endif //USE_INLINE


#endif //BITSET_H
