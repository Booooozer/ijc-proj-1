//
// Created by tom on 3/5/21.
//

#include <stdio.h>
#include <stdarg.h>

#ifndef ERROR_H
#define ERROR_H

void warning_msg(const char *fmt, ...);

void error_exit(const char *fmt, ...);


#endif //ERROR_H
