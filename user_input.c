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
		exit(EXIT_FAILURE);
	}

	/*
	 * to read user input
	 *
	 */
	ssize_t bytesRead = getline(&input, &input_size, stdin);

	if (bytesRead == -1)
	{
		perror("Error reading input");
		free(input);
		exit(EXIT_FAILURE);
	}
	else if (bytesRead == 0)
	{

	/*
	 * for handling Ctrl+D
	 *
	 */
		free(input);
		exit(EXIT_SUCCESS);
	}

	/*
	 * to remove new line if present
	 */
	if (input[bytesRead - 1] == '\n')
	{
		input[bytesRead -1] = '\0';
	}

	return input;

}

