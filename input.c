#include "shell.h"

/**
 * exec_file_command - read command from file and pass
 *                     it to execve
 * @open_file: file to be opened
 * @argv: command from the file
 * Return: the value gottrn from execve
*/


int exec_file_command(int open_file)
{
	char file_count[READ_BUF_SIZE];
	ssize_t read_num;
	int i, my_exec, exit_myshell = 0;
	int content_read = 1;
	char *argv[] =  {NULL, NULL};

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
		argv[0] = file_count;
		my_exec = execmc(argv);
		if (my_exec != 0)
		{
			my_exec = exit_myshell;
		}
	}
	return (exit_myshell);
}
