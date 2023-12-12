#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

#define MAX_INPUT_SIZE 1024

/**
 * executeCommand - execute simple commands in a shell
 *
 * @command: It takes the character for the command execution
 *
 * Return: 0.
 */

void executeCommand(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork failed");
	}
	else if (pid == 0)
	{
		/* Child process */
		int ret = system(command);

		if (ret == -1)
		{
			perror("system failed");
			exit(1);
		}
		exit(0);
	}
	else
	{
		/* Parent process */
		int status;

		waitpid(pid, &status, 0);
	}
}

/**
 * customStrlen - Checks the length of a string
 *
 * @str: the character for the length check
 *
 * Return: the length of the string
 */
int customStrlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * customStrcmp - It's check the string
 *
 * @str1: the first string char
 * @str2: the second string char
 *
 * Return: the str1 and str2
 */
int customStrcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
	{
		i++;
	}
	return (str1[i] - str2[i]);
}
/**
 * main - executes the function in the executeCommand function
 *
 * Return: 0
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];
	int inputLen = customStrlen(input);

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
		if (customStrcmp(input, "exit") == 0)
		{
			break;
		}

		executeCommand(input);
	}

	return (0);
}
