#include "shell.h"

#define MAX_INPUT_SIZE 1024

/**
 * main - executes the function in the executeCommand function
 *
 * Return: 0
 */

int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *args[MAX_ARGS];
	char *token = strtok(input, " ");
	int i = 0;

	while (1)
	{
		printf("$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)
			break;

		/* Remove the trailing newline character */
		input[strcspn(input, "\n")] = 0;

		while (token != NULL && i <  MAX_ARGS - 1)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL; /* set the last element to NULL for execvp */

		/* Check if the input is "exit" or "Ctrl+D" */
		if (strcmp(args[0], "exit") == 0 || feof(stdin))
			break;

		execute_command(args[0], args);
	}

	return (0);
}
