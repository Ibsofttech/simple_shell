#include "shell.h"

/**
 * main - main function to run simple shell
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0
*/

int main(int argc, char **argv)
{
	char *display = "msh$ ";
	char *strings = NULL, *strings_cpy = NULL;
	char *token;
	size_t nums = 0;
	ssize_t get_return;
	char *delim = " \n";
	int tok_number = 0, i, counter;

	while (true)
	{
		write(STDOUT_FILENO, display, 6);
		get_return = getline(&strings, &nums, stdin);
		if (get_return == -1)
		{
			free(strings);
			return (-1);
		}
		strings_cpy = malloc(sizeof(char) * get_return);
		if (strings_cpy == NULL)
			perror("unable to allocate memory");
		strcpy(strings_cpy, strings);
		token = strtok(strings, delim);
		while (token != NULL)
		{
			tok_number++;
			token = strtok(NULL, delim);
		}
		tok_number++;
		argv = malloc(sizeof(char *) * tok_number);
		token = strtok(strings_cpy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		execmc(argv);
	}
	free(strings);
	free(strings_cpy);
	free(argv);
	return (0);
}
