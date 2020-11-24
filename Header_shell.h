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
int _strncmp(char *s1, char *s2, int n);
char *path_parser(char *envvar);


#endif /* Header_shell_H */
