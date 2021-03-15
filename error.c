/*
 * error.c
 * Řešení IJC-DU1
 * Autor: Tomáš Matuš, FIT
 * Login: xmatus37
 * Datum: 15.3.2021
 * Přeloženo: gcc 10.2.0
 */

#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void warning_msg(const char *fmt, ...) {
    va_list args;
    fprintf(stderr, "CHYBA: ");
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}

void error_exit(const char *fmt, ...) {
    va_list args;
    fprintf(stderr, "CHYBA: ");
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(1);
}
