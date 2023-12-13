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

	while (1)
	{
		printf("$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)
			break;

		/* Remove the trailing newline character */
		input[strcspn(input, "\n")] = 0;

		/* Check if the input is "exit" or "Ctrl+D" */
		if (strcmp(input, "exit") == 0 || feof(stdin))
			break;

		execute_command(input);
	}

	return (0);
}
