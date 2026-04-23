#include <unistd.h>

void display_prompt(void)
{
	write(1, "#cisfun$ ", 9);
	/* display shell prompt */
}
