#include "shell.h"

/**
 * rm_newline - removes the new line as a result of enter
 * @str: string to remove newline from
 *
 * Return: nothing
 */

void rm_newline(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			break;
		index++;
	}
	str[index] = '\0';
}

/**
 * rm_comment - neglet inputs after '#'
 *
 * @input: input
 *
 * Return: nothing
 */

void rm_comment(char *input)
{
	int index = 0;

	if (input[index] == '#')
	{
		input[index] = '\0';
	}
	while (input[index])
	{
		if (input[index] == '#' && input[index - 1] == ' ')
		{
			break;
		}
		index++;
	}
	input[index] = '\0';
}
