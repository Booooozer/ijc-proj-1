/*
 * ppm.h
 * Řešení IJC-DU1
 * Autor: Tomáš Matuš, FIT
 * Login: xmatus37
 * Datum: 15.3.2021
 */

#ifndef PPM_H
#define PPM_H

#define IMG_MAX_SIZE 8000*8000*3

// struct to store image information
struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];
};

// reads image and returns pointer to allocated struct
struct ppm * ppm_read(const char * filename);

void ppm_free(struct ppm *p);

#endif //PPM_H
