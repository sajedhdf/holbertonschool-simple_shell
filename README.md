# Simple Shell

## Description

Simple Shell is a basic UNIX command interpreter developed as part of the Holberton School curriculum. It allows users to execute commands through a simple command-line interface.

## Features

* Displays a prompt and waits for user input
* Executes standard system commands
* Works in interactive and non-interactive modes

## Compilation

Compile the program using:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Usage

Run the shell with:

```bash
./hsh
```

You can also use it in non-interactive mode:

```bash
echo "ls" | ./hsh
```

## Example

```bash
$ ./hsh
($) ls
($) exit
```

## Notes

This shell provides a minimal set of features required to execute basic commands.

## Files

* README.md
* man_1_simple_shell
* AUTHORS

## Authors

Sajed Lonie Ronan
