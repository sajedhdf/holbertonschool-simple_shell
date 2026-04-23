# Simple Shell

## Description

This project is a simple UNIX command line interpreter (shell) written in C as part of the Holberton School curriculum.

The shell mimics a basic behavior of a real UNIX shell by reading user input, parsing commands, and executing them using system calls.

It supports both interactive and non-interactive modes.

---

## Features

- Displays a custom prompt: `#cisfun$`
- Executes commands entered by the user
- Supports absolute paths (e.g. `/bin/ls`)
- Searches for commands using the `PATH` environment variable
- Handles invalid commands gracefully
- Works in interactive and non-interactive modes
- Uses `fork`, `execve`, and `wait` system calls

---

## Compilation

To compile the program, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
