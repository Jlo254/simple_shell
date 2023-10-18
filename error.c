#include "shell.h"

/**
 * handle_error - prints error when cmd not found
 * @name: program printed
 * @comd: the command not printed
 * Return: nothing
 */
void handle_error(char *name, char *comd)
{
write(STDERR_FILENO, name, str_len(name));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, "1: ", 3);
write(STDERR_FILENO, comd, str_len(comd));
write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * print_error - function that prints error
 * @name: program printed
 * @comd: the command not printed
 *
 * Return: nothing
 */
void print_error(char *name, char *comd)
{
write(STDERR_FILENO, name, str_len(name));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, comd, str_len(comd));
write(STDERR_FILENO, ": Permission declined\n", 20);
}
