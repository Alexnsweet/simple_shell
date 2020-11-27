#include "Header_shell.h"

/**
 * _exec - executes non-builtin commands
 * @paths: paths
 * @tokens: tokens
 * @path: path
 * @buffer: buffer
 */
void _exec(char **paths, char **tokens, char *path, char *buffer)
{
	char *cmd = NULL;
	pid_t child;
	int i, status;

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
