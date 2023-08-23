#include "shell.h"

/**
 * main - main function to run simple shell
 * @argc: argument count
 * @argv: argument vector
 * Return: Always zero
*/

int main(int argc, char **argv)
{
	char *my_command = NULL;
	char *args[2];
	size_t num = 0;
	ssize_t get_return;

	if (argc == 1 && isatty(STDIN_FILENO))
	{
		while (true)
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

			args[0] = my_command;
			args[1] = NULL;
			execmc(args);
		}
		free(my_command);
		return (0);
	}
	else if (argc == 2)
		return (non_interactive_mode(argv[1]));
	else
		return (1);
}
