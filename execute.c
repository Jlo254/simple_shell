#include "shell.h"

/**
 * my_execute - Function that executes command
 * @execute: Command line to be executed
 *
 * Return: exit
 */
void my_execute(void)
{
	char *user_input = get_user_input();

	if (user_input == NULL)
	{
		exit(EXIT_SUCCESS);
	}

	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		free(user_input);
		exit(EXIT_FAILURE);
	}

	else if (child_pid == 0)
	{
		char **args = tokenize_input(user_input);

		if (execve(args[0], args, NULL) == -1)
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
