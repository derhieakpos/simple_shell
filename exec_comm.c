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
		execlp(command, command, (char *)NULL);
		perror("execvp failed");
		exit(1);
	}
	else
	{
		/* Parent process */
		int status;

		waitpid(pid, &status, 0);
	}
}
