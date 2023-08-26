#include "shell.h"

/**
 * execmc - execute command
 * @args: command areument
 * Return: NULL
*/

int execmc(char **args)
{
	pid_t pid;
	char *command = NULL, *my_command = NULL;
	int my_exec;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Error creating a child process.");
		return (-1);
	}
	else if (pid == 0)
	{
		command = args[0];
		my_command = get_location(command);
		if (my_command == NULL)
		{
			perror("./hsh");
			exit(127);
		}
		my_exec = execve(my_command, args, NULL);
		if (my_exec == -1)
		{
			perror("./hsh");
			exit(2);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
	/*parent process should wait for child process*/
		waitpid(pid, &status, 0);
		return (WIFEXITED(status) ? WEXITSTATUS(status) : -1);
	}
}
