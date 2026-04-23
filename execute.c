#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char **environ;

/**
 * find_path - search full path of a command in PATH
 * @cmd: command entered by user
 *
 * Return: full path if found, otherwise NULL
 */
char *find_path(char *cmd)
{
	char *path = getenv("PATH");
	char *token;
	static char full[1024];

	if (!path)
		return (NULL);

	token = strtok(path, ":");

	while (token)
	{
		/* build full path = directory + "/" + command */
		strcpy(full, token);
		strcat(full, "/");
		strcat(full, cmd);

		/* check if executable exists */
		if (access(full, X_OK) == 0)
			return (full);

		token = strtok(NULL, ":");
	}

	return (NULL);
}

/**
 * execute_command - execute a command using fork and execve
 * @command: user input command
 */
void execute_command(char *command)
{
	pid_t pid;
	char *args[2];
	char *cmd_path;

	/* prepare arguments for execve */
	args[0] = command;
	args[1] = NULL;

	/* try to find command in PATH */
	cmd_path = find_path(command);

	/* if not found in PATH, use raw command */
	if (!cmd_path)
		cmd_path = command;

	/* create child process */
	pid = fork();

	if (pid == 0)
	{
		/* child process executes command */
		if (execve(cmd_path, args, environ) == -1)
		{
			perror("./hsh");
			exit(1);
		}
	}
	else
	{
		/* parent waits for child process */
		wait(NULL);
	}
}
