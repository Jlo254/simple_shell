#ifndef SHELL_H
#define SHELL_H


/* Indicates all headers used */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Indicates read/write buffers */
#define MAX_INPUT_LENGTH 1024


/* Indicates function prototypes used */

void fj_print(const char *func_display);
void my_prompt(void);
void my_execute(void);


#endif /* SHELL_H */
