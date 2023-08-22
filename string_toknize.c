#include "shell.h"

/**
 * string_tok - a function that tokinize an array of strings
 * @strings: string to be tokinized
 * @delim: delimeter
 * Return: array of tokinized string
*/
char *argv[] = {NULL, NULL};

char **string_tok(char *strings, char *delim)
{
	char *token = NULL, *string_cpy = NULL;
	//char *argv[] = {NULL, NULL};
	int num_token = 0, i;

	string_cpy = _strdup(strings);
	token = strtok(string_cpy, delim);
	while (token)
	{
		num_token++;
		token = strtok(NULL, delim);
	}
	num_token++;
	//argv = malloc(sizeof(char *) * num_token);

	//token = NULL;
	//token = strtok(strings, delim);
	argv[0] = token;
	// i = 0;
	// while (token)
	// {
	// 	argv[i] = malloc(sizeof(char) * _strlen(token));
	// 	str_cpy(argv[i], token);
	// 	token = strtok(NULL, delim);
	// 	i++;
	// }
	argv[1] = NULL;
	free(string_cpy);
	return (argv);
}
