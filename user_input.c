#include "shell.h"

char *get_user_input(void)
{
	char *input = NULL;
	size_t input_size = MAX_INPUT_LENGTH;

	/*
	 * for allocating memory for input
	 */
	input = (char *)malloc(input_size);
	if (input == NULL)
	{
	       perror("Memory allocation error");
		_exit(EXIT_FAILURE);
	}

	ssize_t bytesRead;

	/*
	 * bytesRead- used to read user input
	 *
	 */
	bytesRead = read(STDIN_FILENO, input, input_size);

	if (bytesRead == -1)
	{
		perror("Error reading input");
		free(input);
		_exit(EXIT_FAILURE);
	}

	else if (bytesRead == 0)
	{
		free(input);
		return NULL;
	}

	input[bytesRead] = '\0';
	 if (input[bytesRead -1] == '\n');
	 {
		 input[bytesRead -1] = '\0';
	 }

	 return (input);
}
