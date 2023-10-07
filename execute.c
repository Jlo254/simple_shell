#include "shell.h"

/**
 * my_execute - Function that executes command
 * @execute: Command line to be executed
 *
 * Return: exit
 */
void my_execute( const char *execute)
{
	char* args[]=
	{
		"/bin/ls", execute, NULL
	}
{
	pid_t child_pid = fork();

	if (child_pid == -1 )
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
else if (child_pid == 0)
{
	if (execve("/bin/ls", args, NULL) == -1)
	{

	perror("execve");
	exit(EXIT_FAILURE);
}
else
{
	wait(NULL);
}
	return(0);
}

