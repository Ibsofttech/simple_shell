#ifndef SHELL_H
#define SHELLL_h

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
void execmc(char **argv);

#endif