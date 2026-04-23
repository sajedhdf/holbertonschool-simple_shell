#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

extern char **environ;

/**
 * execute_command - executes a command using fork and execve
 * @command: user input command
 */
void execute_command(char *command)
{
	pid_t pid;
	char *args[2];

	args[0] = command;
	args[1] = NULL;

	pid = fork(); /* create child process */

	if (pid == 0)
	{
		/* child process executes command */
		if (execve(command, args, environ) == -1)
		{
			perror("./hsh");
			exit(1);
		}
	}
	else
	{
		wait(NULL); /* parent waits for child */
	}
}
