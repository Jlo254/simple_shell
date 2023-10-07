#include "shell.h"

/**
 * my_execute - Function that executes command
 * It reads a user provided command, forks a new process
 * then executes the command using execve system call
 *
 */
void my_execute(void)
{
	char *user_input = get_user_input();

	if (user_input == NULL)
	{
		exit(EXIT_SUCCESS);
	}

	pid_t child_pid;
	
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		free(user_input);
		exit(EXIT_FAILURE);
	}

	else if (child_pid == 0)
	{
		char *args[] = {user_input, NULL};

		if (execve(user_input, args, NULL) == -1)
		{
			perror("execve")
			free(user_input);
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		int status;

		waitpid(child_pid, &status, 0);

		free(user_input);
	}
}
