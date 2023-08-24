#include "shell.h"

/**
 * execmc - execute command
 * @args: command areument
 * Return: NULL
*/

int execmc(char **args)
{
	pid_t pid;
	char *command = NULL;
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
		/*my_command = get_location(command);*/
		my_exec = execve(command, args, NULL);
		if (my_exec == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
		exit(my_exec);
	}
	else
	{
	/*parent process should wait for child process*/
		waitpid(pid, &status, 0);
		return (WIFEXITED(status) ? WEXITSTATUS(status) : -1);
	}
}
