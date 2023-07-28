#include "shell.h"

/**
 * main - main function to run simple shell
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variable
 * Return: Always 0
*/

int main(int argc __attribute__((unused)), char **argv, char **env)
{
	char *strings = NULL;
	size_t nums = 0;
	int i;

	while (true)
	{
		_write("msh$ ", STDOUT_FILENO);
		if (getline(&strings, &nums, stdin) == -1)
		{
			free(strings);
			exit(EXIT_FAILURE);
		}

		i = 0;
		while (strings[i])
		{
			if (strings[i] == '\n')
				strings[i] = '\0';
			i++;
		}
		argv[0] = strings;
		/*argv = string_tok(strings, " ");*/
		if (argv == NULL)
			continue;
		execmc(argv, env);
	}
	free(strings), free(argv);
	return (0);
}
