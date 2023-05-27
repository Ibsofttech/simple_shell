#ifndef SSHELL_H
#define SSHELL_H

#include <stdarg.h>
#include <stdbool.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "linklist.h"
#include "./memofile/memo.h"
#include "shellvar.h"
#include "./builtinfile/builtin.h"
#include "./errorfile/error.h"
#include "./shellhelperfile/shellhelper.h"

#define SPACE " "
#define EQUAL "="
#define COLON ":"
#define BSLASH "\\"
#define FSLASH "/"
#define BUF_SIZE 4096
#define PS1 write(STDOUT_FILENO, "MANDALORIAN$ ", 4)
#define PS2 write(STDOUT_FILENO, "\nMANDALORIAN$ ", 5)
#define NEWLINE write(STDOUT_FILENO, "\n", 1)
#define DELIM " \t"
#define LOGFILE ".simple_shell_history"
#define MAXLOGSIZE 4096
#define MAXBUFREAD 1024

/* _getline.c */
ssize_t _getline(char **lineptr, size_t *n, int fd, list_t **mt);
void reset_buffer(char *buffer, ssize_t buf_size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strdup(char *str, list_t **mt);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strtok(char *s, const char *delim);
unsigned int _strlen(char *s);
/* string02.c */
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
char *_strcat(char *s1, char *s2, list_t **mt);
char *_itoa(ssize_t num, list_t **mt);
char *reverse_str(char *s);
/* string03.c */
char *_strchr(char *s, char c);
void _chartostr(char *s, char c);
/* log01.c */
int add_log(sev_t *sev);
int write_log(sev_t *sev);
int get_log_count(sev_t *sev);


#endif
