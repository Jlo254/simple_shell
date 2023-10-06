#include "shell.h"


void fj_print(const char *func_display)
{
	write (STDOUT_FILENO, func_display, strlen(func_display));
}
