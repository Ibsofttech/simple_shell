#include "shell.h"

/**
 * execmc - execute command
 * @argv: command areument
 * Return: NULL
*/

int execmc(char **argv)
{
	pid_t pid;
	char *command = NULL;
	int my_exec;

	pid = fork();
	if (pid == -1)
	{
		perror("Error creating a child process.");
		return (-1);
	}
	else if (pid == 0 && argv != NULL)
	{
		command = argv[0];
		/*my_command = get_location(command);*/
		my_exec = execve(command, argv, NULL);
		if (my_exec == -1)
		{
			perror("Error");
		}
		exit(my_exec);
	}
	else
	{
	/*parent process should wait for child process*/
		wait(&my_exec);
		return (my_exec);
	}
}
