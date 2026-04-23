# Simple Shell

This project is a minimal UNIX command line interpreter.

## Compilation
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Usage
./hsh

## Description
This shell reads user input, creates a child process using fork,
and executes commands using execve.
