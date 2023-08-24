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
	int content_read = 1;
	char **args = NULL;

	while (content_read)
	{
		read_num = read(open_file, file_count, sizeof(file_count));
		if (read_num == -1)
		{
			return (-1);
		}
		else if (read_num == 0)
		{
			content_read = 0;
			continue;
		}
		for (i = 0; i < read_num; i++)
		{
			if (file_count[i] == '\n')
				file_count[i] = '\0';
		}
		args = string_tok(file_count, " ");
		my_exec = execmc(args);
		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
		if (my_exec != 0)
		{
			return (my_exec);
		}
	}
	return (0);
}
