#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

char *_strdup(const char *str);
char *str_cpy(char *dest, char *src);
int _strlen(char *s);
void _puts(char *str);
int _putchar(char c);
void execmc(char **argv);
ssize_t get_line(char **strings, size_t *num, FILE *stream);

#endif
