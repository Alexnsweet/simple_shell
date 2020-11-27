#include "Header_shell.h"
/**
 * main - runs simple shell
 *
 * Return: 0 on success
 */
int main(void)
{
char *buffer = NULL, *path = NULL, **tokens, **paths;
size_t buffSize = 0;
int gl, tty;

tty = _ttyprompt(); /* 0 if interactive or 1 if non-interactive */
path = path_parser("PATH="); /* string of path keys with delimeters */
paths = tokenizer(path, ":"); /* returns array of char pointers */
gl = getline(&buffer, &buffSize, stdin);
while (gl > 0)
{
tokens = tokenizer(buffer, " \n\r\f\v");
if (tokens != NULL)
{
	if (isbuiltin(paths, tokens, buffer, path) != 2)
	{	_exec(paths, tokens, path, buffer);	}
		free(tokens);
}
	if (tty == 1)
	{	tty = _ttyprompt();	}
	gl = getline(&buffer, &buffSize, stdin);
}
	free(buffer);
	free(paths);
	free(path);
	return (0);
}
