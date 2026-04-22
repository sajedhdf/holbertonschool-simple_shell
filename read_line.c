#include <stdio.h>
#include <stdlib.h>

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;

	getline(&line, &len, stdin);
	/* read the command entered by the user */

	return (line);
	/* return the command to the shell */
}
