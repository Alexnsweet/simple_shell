#include "Header_shell.h"

int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	char *path = NULL;
	char *cmd = NULL;
	char **tokens;
	char **paths;
	size_t buffSize = 0;
	int gl, i, status, tty;
	(void) ac;
	char *teststr1, *teststr2, *teststr3;
	pid_t child;

	tty = _ttyprompt();
	path = path_parser("PATH=");	
	paths = tokenizer(path, ":");

	gl = getline(&buffer, &buffSize, stdin);
	if (gl == -1)
	{	print_string("could not read line");
	}
	else
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
{
	wait(&status);
}

		free(paths);
		free(tokens);	
		free(buffer);

}

	return (0);
}
