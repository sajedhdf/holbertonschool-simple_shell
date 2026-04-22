#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

extern char **environ;

void execute_command(char *command)
{
	pid_t pid;

	pid = fork();
	/* create a child process */

	if (pid == 0)
	/* child process */
	{
		char *args[] = {command, NULL};
		/* arguments array for execve */

		execve(command, args, environ);
		/* execute the command */

		perror("./simple_shell");
		/* print error if command not found */

		exit(1);
		/* exit child process if execve fails */
	}
	else
	/* parent process */
	{
		wait(NULL);
		/* wait until child process finishes */
	}
}
