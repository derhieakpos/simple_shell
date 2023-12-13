#include "shell.h"


/**
 * executeCommand - execute simple commands in a shell
 *
 * @command: It takes the character for the command execution
 *
 * Return: 0.
 */

void execute_command(char *command)
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
