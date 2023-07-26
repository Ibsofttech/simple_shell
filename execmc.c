#include "shell.h"

/**
 * execmc - execute command
 * @argv: command areument
 * Return: NULL
*/

void execmc(char **argv)
{
	char *command = NULL;
	int my_exec;

	if (argv)
	{
		command = argv[0];
		my_exec = execve(command, argv, NULL);
		if (my_exec == -1)
		{
			perror("error");
		}
	}
}
