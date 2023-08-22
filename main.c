#include "shell.h"

/**
 * main - main function to run simple shell
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0
*/

int main(int argc, char **argv)
{
	char *my_command = NULL;
	size_t num = 0;
	ssize_t get_return;
	int i, my_exec;
	pid_t my_pid;

	if (argc == 1 && isatty(STDIN_FILENO))
	{
		while (true)
		{
			{
				_write("mshell$ ", STDOUT_FILENO);
				get_return = getline(&my_command, &num, stdin);
				if (get_return == -1)
				{
					free(my_command);
					return (-1);
				}
				if (my_command[get_return - 1] == '\n')
					my_command[get_return - 1] = '\0';

				argv[0] = my_command;
				my_exec = execmc(argv);
			}
		}
		free(my_command);
		return (0);
	}
	else
		return (non_interactive_mode(argv[1]));
	return (1);
}
