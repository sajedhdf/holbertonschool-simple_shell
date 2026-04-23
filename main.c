#include <stdlib.h>
#include <unistd.h>
#include "simple_shell.h"

/**
 * main - Entry point of simple shell
 *
 * Description: Reads user input, executes commands, and handles EOF.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *command;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();
		/* show prompt only in interactive mode */

		command = read_line();
		/* read user input */

		if (!command)
			break;
		/* handle EOF (Ctrl+D / pipe) */

		execute_command(command);
		/* execute command */

		free(command);
		/* free memory */
	}

	return (0);
}
