//
// Created by tom on 3/5/21.
//

#include "bitset.h"

#ifdef USE_INLINE

    extern inline unsigned long bitset_size(bitset_t jmeno_pole);

    extern inline void bitset_setbit(bitset_t jmeno_pole, unsigned long index, char vyraz);

    extern inline unsigned long bitset_getbit(bitset_t jmeno_pole, unsigned long index);

#endif
