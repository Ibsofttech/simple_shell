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
		printf("msh$ ");
		if (getline(&strings, &nums, stdin) == -1)
		{
			perror("Exiting shell");
			break;
		}

		i = 0;
		while (strings[i])
		{
			if (strings[i] == '\n')
				strings[i] = '\0';
			i++;
		}
		argv[0] = strings;
		if (argv[0] == NULL)
			continue;
		execmc(argv, env);
	}

	free(strings);
	return (0);
}
