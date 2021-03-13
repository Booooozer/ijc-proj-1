//
// Created by tom on 3/6/21.
//

#include "ppm.h"
#include "error.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// allocate struct for ppm image
struct ppm * ppm_read(const char * filename) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        warning_msg("Chyba otevreni souboru: %s\n", filename);
        return NULL;
    }

    unsigned int xsize, ysize;

    // scan header of ppm P6 image
    if (fscanf(fp,"P6 %u %u 255 ", &xsize, &ysize) != 2) {
        fclose(fp);
        warning_msg("Spatna hlavicka obrazku %s\n", filename);
        return NULL;
    }

    // img size to be allocated
    size_t imgSize = xsize * ysize * 3;
    if (imgSize > IMG_MAX_SIZE) {
        fclose(fp);
        warning_msg("Obrazek %s je prilis velky\n", filename);
        return NULL;
    }

    // alloc struct ppm
    struct ppm *ppmImg = malloc(sizeof(struct ppm) + imgSize);
    if (ppmImg == NULL) {
        fclose(fp);
        warning_msg("Nepodarilo se alokovat pamet pro obrazek %s\n", filename);
        return NULL;
    }
    ppmImg->xsize = xsize;
    ppmImg->ysize = ysize;

    // clear whitespace after "255" in ppm header
    //fgetc(fp);

    // read binary from file and check if real size matches calculated size
    if (fread(ppmImg->data, sizeof(char), imgSize, fp) != imgSize) {
        fclose(fp);
        ppm_free(ppmImg);
        warning_msg("Velikost obrazku %s neodpovida rozliseni\n", filename);
        return NULL;
    }

    // check if everything was read
    if (fgetc(fp) != EOF) {
        fclose(fp);
        ppm_free(ppmImg);
        warning_msg("Chybne zakonceny soubor\n");
        return NULL;
    }

    fclose(fp);
    return ppmImg;
}

// free struct
void ppm_free(struct ppm *p) {
    free(p);
}
