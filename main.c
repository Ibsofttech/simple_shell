#include "shell.h"

/**
 * main - main function to run simple shell
 * @argc: argument count
 * @argv: argument vector
 * Return: Always zero
*/

int main(__attribute__((unused)) int argc, char **argv)
{
	char *my_command = NULL;
	char **args = NULL;
	size_t num = 0;
	ssize_t get_return;
	int shell_exit_status = 0, i;

	if (argv[1] != NULL)
		return (non_interactive_mode(argv[1]));

	while (true)
	{
		if (isatty(STDIN_FILENO))
			_write("mshell$ ", STDOUT_FILENO);
		get_return = getline(&my_command, &num, stdin);
		if (get_return == -1)
		{
			free(my_command);
			exit(shell_exit_status);
		}
		rm_newline(my_command);
		rm_comment(my_command);
		args = string_tok(my_command, " ");
		if (args[0] == NULL)
		{
			free_args(args, i);
		}
		shell_exit_status = execmc(args);
		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
	}
	free(my_command);
	return (shell_exit_status);
}
