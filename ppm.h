//
// Created by tom on 3/6/21.
//

#ifndef PPM_H
#define PPM_H

#define IMG_MAX_SIZE 8000*8000*3

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];
};

struct ppm * ppm_read(const char * filename);

void ppm_free(struct ppm *p);

#endif //PPM_H
