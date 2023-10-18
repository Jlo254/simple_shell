#include "shell.h"
/**
 * my_print - function that prints environ
 * @env:  environ variable array
 *
 * Return: 0
 */
void my_print(char **env)
{
int i = 0;
while (env[i])
{
write(STDOUT_FILENO, env[i], _strlen(env[i]));
write(STDOUT_FILENO, "\n", 1);
i++;
}
}
