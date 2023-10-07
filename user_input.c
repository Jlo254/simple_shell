#include "shell.h"

char *get_user_input(void) {
	fj_print("cisfun$ ");

	char *input = NULL;
	size_t input_size = MAX_INPUT_LENGTH;

	/*
	 * for allocating memory for inpur buffer
	 *
	*/
	input = (char *)malloc(input_size);
	if (input ==NULL) {
		write(STDERR_FILENO, "Memory allocation error\n", 24);
		exit(EXIT_FAILURE);
	}

	/* for reading user input
	 *
	*/
	ssize_t bytesRead = read(STDIN_FILENO, input, input_size);
	if (bytesRead == -1) {
        /*
	 * To handle read error
	 */
        perror("Error reading input");
        free(input);
        exit(EXIT_FAILURE);
    } else if (bytesRead == 0) {
        /*
	 * To handle (Ctrl+D)
	 */
        free(input);
        return NULL;
    }

    /*
     * to null-terminate the input string
     */
    input[bytesRead - 1] = '\0';

    /*
     * to remove newline character if present
     */
    char *newlinePtr = strchr(input, newline);
    if (newlinePtr) {
        *newlinePtr = '\0';
    }


    return input;

}
