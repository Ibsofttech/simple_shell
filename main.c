#include "shell.h"

/**
 * main - main function to run simple shell
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0
*/

int main(int argc __attribute__((unused)), char **argv)
{
	char *strings = NULL;
	size_t nums = 0;
	int i;

	while (true)
	{
		_write("msh$ ", STDOUT_FILENO);
		if (getline(&strings, &nums, stdin) == -1)
		{
			perror("exiting mshell...");
			return (-1);
		}

		i = 0;
		while (strings[i])
		{
			if (strings[i] == '\n')
				strings[i] = '\0';
			i++;
		}
		argv = string_tok(strings, " ");
		if (argv == NULL)
			continue;
		execmc(argv);
	}
	free(strings), free(argv);
	return (0);
}
