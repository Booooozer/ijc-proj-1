//
// Created by tom on 3/1/21.
//
#include <limits.h>
#include <stdlib.h>

#ifndef BITSET_H
#define BITSET_H

typedef unsigned long bitset_t;

typedef unsigned long bitset_index_t;

#define ULONG_BIT (sizeof(unsigned long) * CHAR_BIT)

// creates static array on stack
#define bitset_create(jmeno_pole,velikost)_Static_assert(velikost > 0, "Velikost pole musi byt vetsi nez 0"); \
                    bitset_t jmeno_pole [(velikost / ULONG_BIT) + ((velikost % ULONG_BIT) ? 1 : 0)] = {velikost};

// allocates array on heap
#define bitset_alloc(jmeno_pole,velikost)(velikost > 0, "Velikost pole musi byt vetsi nez 0");  \
        bitset_t *jmeno_pole = calloc(((velikost / ULONG_BIT) +                                 \
        ((velikost % ULONG_BIT) ? 1 : 0)), sizeof(unsigned long));                              \
        if(jmeno_pole == NULL) {                                                                \
            fprintf(stderr, "bitset_alloc: Chyba alokace pameti");                              \
            return 1;                                                                           \
        }                                                                                       \
        *jmeno_pole = velikost;

#define bitset_free(jmeno_pole) \
    free(jmeno_pole);           \
    jmeno_pole = NULL;

// something is wrong with it 
bitset_alloc(a,10)


#endif //BITSET_H
