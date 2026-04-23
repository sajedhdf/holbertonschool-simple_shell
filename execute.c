#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/**
 * find_cmd - search full path of a command in PATH
 * @cmd: command typed by user (example: "ls")
 *
 * Return: full path if found (example: "/bin/ls")
 *         or NULL if not found
 */
char *find_cmd(char *cmd)
{
	char *path = getenv("PATH");   /* get system PATH */
	char *copy;                    /* we copy PATH because strtok modifies it */
	char *token;                  /* each folder in PATH */
	static char full[1024];       /* final path buffer */

	/* if PATH doesn't exist, we stop */
	if (!path)
		return (NULL);

	/* duplicate PATH to avoid modifying original */
	copy = strdup(path);
	if (!copy)
		return (NULL);

	/* split PATH into folders */
	token = strtok(copy, ":");

	while (token)
	{
		/* build full path: folder + "/" + command */
		strcpy(full, token);
		strcat(full, "/");
		strcat(full, cmd);

		/* check if file exists and is executable */
		if (access(full, X_OK) == 0)
		{
			free(copy); /* free memory before returning */
			return (full);
		}

		/* move to next PATH folder */
		token = strtok(NULL, ":");
	}

	free(copy); /* free memory if not found */
	return (NULL);
}

/**
 * execute_command - executes a command using fork + execve
 * @command: user input (example: "ls")
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
	cmd_path = find_cmd(command);

	/* if not found, use raw command (useful for /bin/ls) */
	if (!cmd_path)
		cmd_path = command;

	/* create child process */
	pid = fork();

	if (pid == 0)
	{
		/* CHILD: execute command */
		if (execve(cmd_path, args, environ) == -1)
		{
			/* if execution fails */
			write(2, "./hsh: command not found\n", 26);
			exit(1);
		}
	}
	else
	{
		/* PARENT: wait child to finish */
		wait(NULL);
	}
}
