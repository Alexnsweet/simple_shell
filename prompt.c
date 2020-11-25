#include "Header_shell.h"

int main(void)
{
	char *buffer = NULL;
	char *path = NULL;
	char *cmd = NULL;
	char **tokens;
	char **paths;
	size_t buffSize = 0;
	int gl, i, status, tty;

	pid_t child;

	tty = _ttyprompt(); /* 0 if interactive or 1 if non-interactive */
	path = path_parser("PATH="); /* string of path keys with delimeters */
	paths = tokenizer(path, ":"); /* returns array of char pointers */

	gl = getline(&buffer, &buffSize, stdin);
/*	if (gl == -1)
	{	print_string("could not read line");
	}
*/	if (gl > 0)
	{
		tokens = tokenizer(buffer, " \n\r\f\v");

		/*begin child process */

		child = fork();

		if (child == 0)
		{
			for (i = 0; paths[i]; i++)
			{

				cmd = concat(paths[i], tokens[0]);
/*
				printf("cmd: %s\n", cmd);
				printf("cmd: %s\n", cmd);
*/
				execve(cmd, tokens, environ);

				free(cmd);
			}

			print_string("Command not found, buddy. Try again\n");
			free(paths);
			free(tokens);
			free(buffer);

			exit(EXIT_SUCCESS);
		}
		else
		{	wait(&status);	}

			free(paths);
			free(tokens);	
			free(buffer);

	}

	return (0);
}
