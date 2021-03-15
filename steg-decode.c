/*
 * steg-decode.c
 * Řešení IJC-DU1
 * Autor: Tomáš Matuš, FIT
 * Login: xmatus37
 * Datum: 15.3.2021
 */

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

    unsigned char msgByte = 0;
    int count = 0;
    for (unsigned i = 23; i < arrSize; i++) {
        // index is prime
        if (bitset_getbit(p,i) == 0) {
            // get LSB from image data and put it to index in byte starting from LSB
            msgByte |= ((img->data[i] & 1) << count);
            count++;

            // last bit in byte is filled
            if (count == CHAR_BIT) {
                count = 0;
                putchar(msgByte);
                // end of message
                if (msgByte == '\0') {
                    putchar('\n');
                    break;
                }
                // message doesn't end with '\0'
                if (i == arrSize - 1) {
                    warning_msg("Skryta zprava je nespravne ukoncena!\n");
                }
                msgByte = 0;
            }
        }
    }

    ppm_free(img);
    bitset_free(p)

    return 0;
}
