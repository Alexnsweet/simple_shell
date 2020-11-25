#include "Header_shell.h"

int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	char *path, *cmd;
	char **tokens;
	char **paths;
	size_t buffSize = 0;
	int gl, i, status;
	(void) ac;
	char *teststr1, *teststr2, *teststr3;
	pid_t child;


	if (isatty(STDIN_FILENO))
	{	write (STDOUT_FILENO, "($) ", 4);	}
	else if (isatty(STDIN_FILENO) != 1)
	{	write (STDOUT_FILENO, "$ ", 2);	}

/* test _strcat and concat
teststr1 = "Hello world, ";
teststr2 = "it's nice to see you.";

printf("%s\n", teststr1);

teststr3 = concat(teststr1, teststr2);

printf("%s\n", teststr3);
*/
	path = path_parser("PATH=");
	
	paths = tokenizer(path, ":");
/*
	for (i = 0; paths[i]; i++)
	{
		print_string(paths[i]);
		print_string("\n");
	}
*/
	gl = getline(&buffer, &buffSize, stdin);
	if (gl == -1)
	{	print_string("could not read line");
	}
	else
	{
		/* take out '\n' character */
/*		i = 0;

		while (buffer[i] != '\n')
		{
			i++;
		}
		buffer[i] = '\0';
*/
		tokens = tokenizer(buffer, " \n\r\f\v");
		for (i = 0; tokens[i]; i++)
		{
			print_string(tokens[i]);
			print_string("\n");
		}

/*begin child process */

child = fork();

if (child == 0)
{
	for (i = 0; paths[i]; i++)
	{

		cmd = concat(paths[i], tokens[0]);

		printf("cmd: %s\n", cmd);
		printf("cmd: %s\n", cmd);

		execve(cmd, tokens, environ);

		free(cmd);
	}

		print_string("Command not found, buddy");

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
