#include "shell.h"

/**
 * exec_file_command - read command from file and pass
 *                     it to execve
 * @open_file: file to be opened
 * Return: the value gottrn from execve
*/


int exec_file_command(int open_file)
{
	char file_count[READ_BUF_SIZE];
	ssize_t read_num;
	int i, my_exec;
	char **args = NULL;

	while (read(open_file, file_count, sizeof(file_count) != -1))
	{
		for (i = 0; i < read_num; i++)
		{
			if (file_count[i] == '\n')
				file_count[i] = '\0';
		}
		rm_newline(file_count);
		args = string_tok(file_count, " ");
		if (args[0] == NULL)
		{
			free_args(args, i);
			break;
		}
		
		my_exec = execmc(args);
		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
	}
	return (my_exec);
}
