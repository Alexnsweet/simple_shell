#include "Header_shell.h"

int main(void)
{
	char *buffer = NULL, *path = NULL, *cmd = NULL;
	char **tokens, **paths;
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
		isbuiltin(paths, tokens, buffer);
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
			free(tokens);
			free(buffer);
			_exit(2);
		}
		else
		{	wait(&status);	}
			free(tokens);	
	}
		if (tty == 1)
		{	tty = _ttyprompt();	}
		gl = getline(&buffer, &buffSize, stdin);
	}
		free(buffer);
		free(paths);
	return (0);
}
