#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

extern char **environ;

void execute_command(char *command)
{
	pid_t pid;
	char *args[2];
	/* arguments array for execve */

	args[0] = command;
	args[1] = NULL;

	pid = fork();
	/* create child process */

	if (pid == 0)
	/* child process */
	{
		execve(command, args, environ);
		/* execute the command */

		perror("./simple_shell");
		/* print error if command fails */

		exit(1);
		/* exit child process */
	}
	else
	/* parent process */
	{
		wait(NULL);
		/* wait for child process */
	}
}
