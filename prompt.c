#include "Header_shell.h"
/**
 * main - runs simple shell
 *
 * Return: 0 on success
 */
int main(void)
{
char *buffer = NULL, *path = NULL, *cmd = NULL, **tokens, **paths;
size_t buffSize = 0;
int i, gl, status, tty;
pid_t child;

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
	{
		child = fork();
		if (child == 0)
		{
			for (i = 0; paths[i]; i++)
			{
				if (execve(tokens[0], tokens, environ) == -1)
				{
				cmd = concat(paths[i], tokens[0]);
				execve(cmd, tokens, environ);
				}
				free(cmd);
			}
			print_string("Command not found, buddy. Try again\n");
			free(paths);
			free(path);
			free(tokens);
			free(buffer);
			_exit(0);
		}
		else
		{	wait(&status);	}
	}
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
