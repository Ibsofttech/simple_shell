#include "shell.h"

/**
 * non_interactive_mode - user enter commad
 * @env: environment variable
 * Return: null
*/

int non_interactive_mode(void)
{
	char *my_command = NULL, **argv;
	size_t num = 0;
	ssize_t get_return;
    int i, my_exec;
	
	if (!isatty(STDIN_FILENO))
    {
        while (true)
	    {   
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
