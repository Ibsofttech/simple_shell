#include "shell.h"

/**
 * main - main function to run simple shell
 * @argc: argument count
 * @env: environment variable
 * Return: Always 0
*/

int main(int argc __attribute__((unused)), char **env)
{
	bool interactive = isatty(STDIN_FILENO);

	if (interactive)
	{
		interactive_mode(env);
	}
	else
	{
		non_interactive_mode(env);
	}

	return (0);
}
