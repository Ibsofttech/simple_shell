#include "shell.h"

/**
 * non_interactive_mode - user enter commad
 * @my_file: file containing the commands
 * Return: null
*/

int non_interactive_mode(const char *my_file)
{
	int open_file, my_exec;

	open_file = open(my_file, O_RDONLY);
	if (open_file == -1)
	{
		perror("error opening file");
		return (1);
	}

	my_exec = exec_file_command(open_file);
	close(open_file);
	return (my_exec);
}
