#ifndef UTIL_H
#define UTIL_H

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int boolean;

void boolean_print(boolean bool);

char *read_line();
char *file_read_line(FILE* file);

void extra_line_end();

#endif //UTIL_H