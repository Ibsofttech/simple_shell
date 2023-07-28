#include "shell.h"

/**
 * execmc - execute command
 * @argv: command areument
 * @env: environment variable
 * Return: NULL
*/

int execmc(char **argv, char **env)
{
    pid_t pid;
    char *command = NULL;
    int my_exec;

    pid = fork();
    if (pid == -1)
    {
        perror("Error creating a child process.");
        return (-1);
    }
    else if (pid == 0)
    {
        command = argv[0];
        my_exec = execve(command, argv, env);
        if (my_exec == -1)
        {
            perror("Error");
        }
        exit(my_exec);
    }
    else
    {
        /*Parent process waits for child process*/
        wait(&my_exec);
        return my_exec;
    }
}
