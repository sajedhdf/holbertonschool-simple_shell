#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

void display_prompt(void);
char *read_line(void);
void execute_command(char *command);

#endif
