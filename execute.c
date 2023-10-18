#include "shell.h"

/**
 * fj_execute - function that executes a command
 * @argv: indicates argument vector
 * @av: exact program to execute
 * @env: shows the environment variable
 *
 * Return: 0 on success, -1 on error
 */

int fj_execute(char **argv, char **av, char **env)
{
pid_t child_pid;
int status;
child_pid = fork();
if (child_pid < 0)
{
perror("Error");
return (-1);
}
if (child_pid == 0)
{
if (execve(argv[0], argv, env) == -1)
{
perror(av[0]);
return (-1);
}
}
else
{
wait(&status);
}
return (0);
}
