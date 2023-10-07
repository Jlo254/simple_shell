#include "shell.h"

/*
 * main - Entry point of the simple shell program
 * It serves as an entry point for the simple shell program
 * it prompts the user for input and executes the commnd
 *
 *Return: 0 on successful execution
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
{
	my_prompt();
	my_execute();
}
	return (0);
}
