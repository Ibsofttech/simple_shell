#include "shell.h"

/**
 * string_tok - a function that tokinize an array of strings
 * @strings: string to be tokinized
 * @delim: delimeter
 * Return: array of tokinized string
*/

char **string_tok(char *strings, char *delim)
{
	char *token = NULL, *string_cpy = NULL;
	char **args = NULL;
	int num_token = 0, i = 0;

	string_cpy = _strdup(strings);
	if (string_cpy == NULL)
		return (NULL);
	token = strtok(string_cpy, delim);
	while (token)
	{
		num_token++;
		token = strtok(NULL, delim);
	}
	num_token++;
	args = malloc(sizeof(char *) * num_token);
	if (args == NULL)
	{
		free(string_cpy);
		return (NULL);
	}
	token = NULL;
	token = strtok(strings, delim);
	i = 0;
	while (token)
	{
		args[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (args[i] == NULL)
		{
			free_args(args, i);
			free(string_cpy);
			return (NULL);
		}
		str_cpy(args[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	args[i] = NULL;
	free(string_cpy);
	return (args);
}

/**
 * free_args - function that free args allocated space
 * @args: memory allocated
 * @count: number of allocated memory
 * Return: null
*/

void free_args(char **args, int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		free(args[i]);
	}
	free(args);
}
