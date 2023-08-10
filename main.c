#include "shell.h"

/**
 * main - main function to run simple shell
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variable
 * Return: Always 0
*/

int main(int argc __attribute__((unused)), char **argv)
{
	char *my_command = NULL;
	size_t num = 0;
	ssize_t get_return;
    int i, my_exec;
	pid_t my_pid;
	
	while (true)
	{
		
		{
			non_interactive_mode();
			_write("mshell$ ", STDOUT_FILENO);
			get_return = getline(&my_command, &num, stdin);

    		if (get_return == -1)
				{
            		free(my_command);
            		return (-1);
				}
    		
    		argv = string_tok(my_command, " \n");

    		my_exec = execmc(argv);
		}
	}
	free(my_command);
}
