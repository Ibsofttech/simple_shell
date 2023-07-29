#include "shell.h"

/**
 * interactive_mode - user enter commad
 * @env: environment variable
 * Return: null
*/
void interactive_mode(char  **env)
{
	char *strings = NULL;
	char *argv[2];
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
		argv[1] = NULL;
		if (argv[0] == NULL)
			continue;
		execmc(argv, env);
	}

	free(strings);
}
