#include <unistd.h>

/**
 * display_prompt - prints shell prompt
 *
 * Description: Displays "#cisfun$ " when shell is in interactive mode
 */
void display_prompt(void)
{
	write(1, "#cisfun$ ", 9);
	/* display shell prompt */
}
