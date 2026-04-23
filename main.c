#include <stdlib.h>
#include "simple_shell.h"

int main(void)
{
	char *command;

	while (1)
	{
		display_prompt();
		/* print prompt */

		command = read_line();
		/* get user input */

		if (!command)
			continue;

		execute_command(command);
		/* run command */

		free(command);
		/* free memory */
	}

	return (0);
}
