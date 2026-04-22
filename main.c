#include <stdio.h>
#include <stdlib.h>
#include "simple_shell.h"

int main(void)
{
	char *command;

	while (1)
	/* infinite loop to keep the shell running */
	{
		display_prompt();
		/* show the shell prompt */

		command = read_line();
		/* read the command from the user */

		execute_command(command);
		/* execute the command */

		free(command);
		/* free memory used by the command */
	}

	return (0);
}
