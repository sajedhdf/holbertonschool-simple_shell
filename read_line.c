#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	/* read command from user */

	if (nread == -1)
	{
		free(line);
		exit(0);
	}

	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';
	/* remove newline */

	return (line);
}
