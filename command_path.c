#include "shell.h"

/**
 * get_command_path - It gets the command path
 *
 * @command: It locks the str into a malloc
 *
 * Return: NULL.
 */

char *get_command_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *path_token = strtok(path_copy, ":");
	char *file_path = malloc(strlen(path) + strlen(command) + 2);

	while (path_token != NULL)
	{
		sprintf(file_path, "%s/%s", path_token, command);
		if (access(file_path, X_OK) != -1)
		{
			free(path_copy);
			return (file_path);
		}
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	free(file_path);
	return (NULL);
}
