/*
 * bitset.c
 * Řešení IJC-DU1
 * Autor: Tomáš Matuš, FIT
 * Login: xmatus37
 * Datum: 15.3.2021
 * Přeloženo: gcc 10.2.0
 */

#include "bitset.h"

#ifdef USE_INLINE

    extern inline unsigned long bitset_size(bitset_t jmeno_pole);

    extern inline void bitset_setbit(bitset_t jmeno_pole, unsigned long index, char vyraz);

    extern inline unsigned long bitset_getbit(bitset_t jmeno_pole, unsigned long index);

#endif
