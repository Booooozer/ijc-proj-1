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

    unsigned char msgByte;
    int count = 0;
    for (unsigned i = 23; i < arrSize; i++) {
        // index is prime
        if (bitset_getbit(p,i) == 0) {

            //bitset_setbit(msgByte,count,(img->data[i] & 1));
            msgByte |= ((img->data[i] & 1) << count);
            count++;
            // last bit in byte is filled
            if (count == CHAR_BIT) {
                count = 0;
                putchar(msgByte);
                if (msgByte == '\0') {
                    putchar('\n');
                    break;
                }
                msgByte = 0;
            }
        }
    }



    ppm_free(img);
    bitset_free(p)

    return 0;
}
