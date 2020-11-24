#ifndef HEADER_SHELL_H
#define HEADER_SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/* String helper functions */
int print_string(char *str);
int _strlen(char *s);
char **tokenizer(char *str, char *delim);
int _strncmp(char *s1, char *s2, size_t n);
char *path_parser(char *envvar);
char *_strcat(char *dest, char *src);
char *catcmd(char **paths, char **tokens);
char *_strcpy(char *dest, char *src);
char *concat(char *str, char *str2);
#endif /* Header_shell_H */
