//
// Created by tom on 3/7/21.
//

#include "ppm.h"
#include "eratosthenes.h"
#include "error.h"
#include "bitset.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char **argv) {

    if (argc != 2) {
        error_exit("Pouze 1 vstupni argument!\n");
    }

    struct ppm *img = ppm_read(argv[argc - 1]);
    if (img == NULL) {
        error_exit("Obrazek nelze nacist\n");
    }

    unsigned arrSize = 3 * img->xsize * img->ysize;
    bitset_alloc(p,arrSize)
    Eratosthenes(p);

    char msgByte[2] = {CHAR_BIT, 0};
    int count = 0;
    for (unsigned i = 23; i < arrSize; i++) {
        // index is prime
        if (bitset_getbit(p,i) == 0) {
            bitset_setbit(msgByte, count, bitset_getbit((&(img->data[i])),7));  // SEGFAULT HERE
            count++;
            // last bit in byte is filled
            if (count > 7) {
                count = 0;
                putchar(msgByte[0]);
                if (msgByte[0] == '\0') {
                    return 0;
                }
            }
        }
    }




    bitset_free(p)

    return 0;
}
