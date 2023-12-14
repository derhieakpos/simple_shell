#include "shell.h"


/**
 * execute_command - execute simple commands in a shell
 *
 * @command: It takes the character for the command execution
 * @args: The argument str
 *
 * Return: 0.
 */

void execute_command(char *command, char *args[])
{
	char *command_path = get_command_path(command);
	pid_t pid = fork();

	if (command_path == NULL)
	{
		printf("Command '%s' not found\n", command);
		return;
	}

	if (pid == -1)
	{
		perror("fork failed");
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execve(command_path, args, NULL) == -1)
		{
			perror("execve failed");
			exit(1);
		}
	}
	else
	{
		/* Parent process */
		int status;

		waitpid(pid, &status, 0);
	}

	free(command_path);
}
