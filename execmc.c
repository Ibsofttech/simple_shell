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
	int my_exec, com_length;

	pid = fork();
	if (pid == -1)
	{
		perror("Error creating a child process.");
		return (-1);
	}
	else if (pid == 0)
	{
		command = argv[0];
		/*my_command = get_location(command);*/
		com_length = _strlen(command);
		if (command[com_length - 1] == '\n')
			command[com_length - 1] = '\0';
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
