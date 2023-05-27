#include "sshell.h"

/**
 * main - totest my_command function
 * @ac: argument count
 * @av: argument vector
 * @ev: environmnet variable
 * Return: always 0
 */

int main(int ac, char **av, char **ev)
{
	sev_t sev;
	int exitcode = 0;
	(void)ac;
	init_shell_env(&sev, av, ev);

	while (sev.skywalker)
	{
		dis_prompt(sev);
		getcom(&sev);
		checker_alias(&sev);
		if (!check_builtin(&sev))
			actions(&sev);
		dis_error(&sev);
	}
	write_log(&sev);
	exitcode = sev.error;
	cl_sev(&sev);
	return (exitcode);
}
