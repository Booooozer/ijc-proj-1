//
// Created by tom on 3/6/21.
//

#ifndef PROJ1_PPM_H
#define PROJ1_PPM_H

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];
};

struct ppm * ppm_read(const char * filename);

void ppm_free(struct ppm *p);

#endif //PROJ1_PPM_H
