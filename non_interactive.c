#include "shell.h"

/**
 * non_interactive_mode - user enter commad
 * @env: environment variable
 * Return: null
*/

void non_interactive_mode(char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, stdin)) != -1)
	{
		/*Process the command without showing any prompts*/
		char *argv[2];

		argv[0] = line;
		argv[1] = NULL;
		execmc(argv, env);
	}

	free(line);
}
