#include "sshell.h"

/**
 * my_command - to execute a normal shell command without error
 * @argv: argument vector
 * @envir:  evironmental variable
 * Return:  no error return
 */

void my_command(char **argv, char **envir)
{
	char *my_string = NULL;
	int i, status;
	size_t n = 0;
	ssize_t num_char;
	char *args[] = {NULL, NULL};
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("cisfun$ ");

		num_char = getline(&my_string, &n, stdin);
		if (num_char == -1)
		{
			free(my_string);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (my_string[i])
		{
			if (my_string[i] == '\n')
				my_string[i] = 0;
			i++;
		}
		args[0] = my_string;
		child_pid = fork();
		if (child_pid == -1)
		{
			free(my_string);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(args[0], args, envir) == -1)
				printf("%s: No such file or directory\n", argv[0]);
		}
		else
			wait(&status);
	}
}
