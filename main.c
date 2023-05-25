#include "sshell.h"

/**
 * main - totest my_command function
 * @argc: argument count
 * @argv: argument vector
 * @envir: environmnet variable
 * Return: always 0
 */

int main(int argc, char **argv, char **envir)
{
	if (argc == 1)
		my_command(argv, envir);
	return (0);
}
