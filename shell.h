#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

char *_strdup(const char *str);
char *str_cpy(char *dest, char *src);
int _strlen(char *s);
void _puts(char *str);
int _putchar(char c);
char *_strcat(char *dest, char *src);
int execmc(char **argv);
ssize_t get_line(char **strings, size_t *num, FILE *stream);
void _write(char *str, int stm);
char **string_tok(char *strings, char *delim);
char *get_location(char *command);
int _strcmp(char *s1, char *s2);
int _strncmp(char *str1, char *str2, size_t n);
char *get_location(char *command);
int file_exists(char *path);
char *find_command_in_path(char *command, char *path);
int non_interactive_mode(void);
int _getline(void);

#endif
