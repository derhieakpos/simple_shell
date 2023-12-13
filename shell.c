#include "shell.h"

#define MAX_INPUT_SIZE 1024

/**
 * main - executes the function in the executeCommand function
 *
 * @custom_strlen: checks the string length
 * @custom_strcmp: compares the strings
 *
 * Return: 0
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];
	int inputLen = strlen(input);

	while (1)
	{
		printf("$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}

		/* Remove the trailing newline character */
		if (input[inputLen - 1] == '\n')
		{
			input[inputLen - 1] = '\0';
		}

		/* Check if the input is "exit" */
		if (strcmp(input, "exit") == 0)
		{
			break;
		}

		execute_command(input);
	}

	return (0);
}
