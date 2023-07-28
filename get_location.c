#include "shell.h"

/**
 * find_command_in_path - to find the correct path
 * @command: command to be executed
 * @path: possible path of the command
 * Return: the correct path of the command
*/

char *find_command_in_path(char *command, char *path)
{
	char *path_copy, *p_token, *full_path;
	int command_length, token_length;

	if (!path)
		return (NULL);
	path_copy = _strdup(path);
	command_length = _strlen(command);
	p_token = strtok(path_copy, ":");

	while (p_token != NULL)
	{
		token_length = _strlen(p_token);
		full_path = malloc(token_length + command_length + 2);
		str_cpy(full_path, p_token);
		_strcat(full_path, "/");
		_strcat(full_path, command);
		_strcat(full_path, "\0");

		if (file_exists(full_path))
		{
			free(path_copy);
			return (full_path);
		}
		else
		{
			free(full_path);
			p_token = strtok(NULL, ":");
		}
	}

	free(path_copy);
	return (NULL);
}

/**
 * get_location - a function that get the env variable
 * @command: commmand to be executed
 * Return: location of the command
*/

char *get_location(char *command)
{
	char *path, *command_location;

	path = getenv("PATH");
	command_location = find_command_in_path(command, path);

	if (command_location)
	{
		return (command_location);
	}

	/*Check if the command exists in the current working directory*/
	if (file_exists(command))
		return (strdup(command));

	return (NULL);
}

/**
 * file_exists - to check if command exist in a path
 * @path: possible paths
 * Return: 0 if path exist
*/

int file_exists(char *path)
{
	struct stat buffer;

	return (stat(path, &buffer) == 0);
}

