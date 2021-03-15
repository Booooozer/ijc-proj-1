/*
 * error.h
 * Řešení IJC-DU1
 * Autor: Tomáš Matuš, FIT
 * Login: xmatus37
 * Datum: 15.3.2021
 * Přeloženo: gcc 10.2.0
 */

#include <stdio.h>
#include <stdarg.h>

#ifndef ERROR_H
#define ERROR_H

void warning_msg(const char *fmt, ...);

void error_exit(const char *fmt, ...);


#endif //ERROR_H
