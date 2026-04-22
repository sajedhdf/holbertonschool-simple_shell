#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

void display_prompt(void);
/* function to display the shell prompt */

char *read_line(void);
/* function to read the user command */

void execute_command(char *command);
/* function to execute the command */

#endif
