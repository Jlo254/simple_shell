#ifndef SHELL_H
#define SHELL_H


/* Indicates all Headers */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

/* PROTOTYPES USED */

void fj_print(const char *func_display);
void my_prompt(void);
void my_execute( const char *execute);


#endif
