#include "sshell.h"

/**
 * my_command - to execute a normal shell command without error
 * @argv: argument vector
 * @envir:  evironmental variable
 * Return:  no error return
 */

void my_command(char **argv, char **envir)
{
	char *my_string = NULL; /*msg = "cisfun$ "*/
	int i = 0, status;
	size_t n = 0;
	ssize_t num_char;
	char *args[] = {NULL, NULL};
	bool from_pipe = false;
	pid_t child_pid;

	while (1 && !from_pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			from_pipe = true;
		/*write(1, msg, 8);*/
		printf("cisfun$ ");
		num_char = getline(&my_string, &n, stdin);
		if (num_char == -1)
		{
			free(my_string);
			exit(EXIT_FAILURE);
		}
		while (my_string[i])
		{
			if (my_string[i] == '\n')
				my_string[i] = '\0';
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
			if (execve(args[0], argv, envir) == -1)
				printf("%s: No such file or directory\n", argv[0]);
		}
		else
			wait(&status);
	}
}
