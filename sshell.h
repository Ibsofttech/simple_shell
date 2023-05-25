#ifndef SSHELL_H
#define SSHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int _islower(int c);
void my_command(char **argv, char **envir);

#endif
