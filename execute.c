#define _GNU_SOURCE
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;
/**
 * find_cmd - search a command in PATH
 * @cmd: command typed by user
 *
 * Return: full path if found, NULL otherwise
 */
char *find_cmd(char *cmd)
{
	char *path = getenv("PATH");
	char *copy;
	char *token;
	static char full[1024];

	if (!path)
		return (NULL);

	/* copy PATH because strtok modifies the string */
	copy = strdup(path);
	if (!copy)
		return (NULL);

	token = strtok(copy, ":");

	while (token)
	{
		/* build full path */
		strcpy(full, token);
		strcat(full, "/");
		strcat(full, cmd);

		/* check if executable exists */
		if (access(full, X_OK) == 0)
		{
			free(copy);
			return (full);
		}

		token = strtok(NULL, ":");
	}

	free(copy);
	return (NULL);
}

/**
 * execute_command - execute user command
 * @command: input command
 */
void execute_command(char *command)
{
	pid_t pid;
	char *args[2];
	char *cmd_path;

	/* prepare arguments for execve */
	args[0] = command;
	args[1] = NULL;

	/* search command in PATH */
	cmd_path = find_cmd(command);

	/* if not found, try raw command (/bin/ls etc) */
	if (!cmd_path)
		cmd_path = command;

	pid = fork();

	if (pid == 0)
	{
		/* child process executes command */
		if (execve(cmd_path, args, environ) == -1)
		{
			write(2, "./hsh: command not found\n", 26);
			exit(1);
		}
	}
	else
	{
		/* parent waits for child */
		wait(NULL);
	}
}
