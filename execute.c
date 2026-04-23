#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char **environ;

char *find_command(char *cmd)
{
	char *path = getenv("PATH");
	char *token;
	static char full[1024];

	token = strtok(path, ":");
	while (token)
	{
		strcpy(full, token);
		strcat(full, "/");
		strcat(full, cmd);

		if (access(full, X_OK) == 0)
			return (full);

		token = strtok(NULL, ":");
	}
	return (NULL);
}

void execute_command(char *command)
{
	pid_t pid;
	char *args[2];
	char *cmd_path;

	args[0] = command;
	args[1] = NULL;

	cmd_path = find_command(command);
	if (!cmd_path)
		cmd_path = command;

	pid = fork();

	if (pid == 0)
	{
		if (execve(cmd_path, args, environ) == -1)
		{
			perror("./hsh");
			exit(1);
		}
	}
	else
		wait(NULL);
}
