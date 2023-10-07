#include "shell.h"

/**
 * fj_print- function that prints stdout
 * @func_display: prints string
 *  
 * Return: printed strlen
 */

void fj_print(const char *func_display)
{
	size_t length = strlen(func_display);
	write(STDOUT_FILENO, func_display, length);
}
