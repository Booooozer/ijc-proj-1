#include <stdio.h>
#include "bitset.h"

int main() {
    bitset_create(p,200000L)
    bitset_alloc(o, 200000L)

    printf("%lu and macro %lu\n",p[0], bitset_size(p));
    printf("%lu and macro %lu\n",o[0], bitset_size(o));


    if (bitset_getbit(p,100)) {
        printf("+");
    } else {
        printf("-");
    }
    printf("\n");

    bitset_setbit(p,100,1);
    if (bitset_getbit(p,100)) {
        printf("+");
    } else {
        printf("-");
    }
    printf("\n");

    bitset_setbit(p,100,0);
    if (bitset_getbit(p,100)) {
        printf("+");
    } else {
        printf("-");
    }
    printf("\n");

    printf("%lu and macro %lu\n",p[0], bitset_size(p));
    printf("%lu and macro %lu\n",o[0], bitset_size(o));
    bitset_free(o)
    return 0;
}
