#include "Header_shell.h"

int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	char *path, *cmd;
	char **tokens;
	char **paths;
	size_t buffSize = 0;
	int gl, i;
	(void) ac;
	char *teststr1, *teststr2, *teststr3;

	if (isatty(STDIN_FILENO))
	{	write (STDOUT_FILENO, "($) ", 4);	}
	else if (isatty(STDIN_FILENO) != 1)
	{	write (STDOUT_FILENO, "$ ", 2);	}

/* test _strcat and concat */
teststr1 = "Hello world, ";
teststr2 = "it's nice to see you.";

printf("%s\n", teststr1);
/*
*teststr3 = concat(teststr1, teststr2);

printf("%s\n", teststr3);
*/
	path = path_parser("PATH=");
	
	paths = tokenizer(path, ":");

	for (i = 0; paths[i]; i++)
	{
		print_string(paths[i]);
		print_string("\n");
	}

	gl = getline(&buffer, &buffSize, stdin);
	if (gl == -1)
	{	print_string("could not read line");
	}
	else
	{
		tokens = tokenizer(buffer, " ");
		for (i = 0; tokens[i]; i++)
		{
			print_string(tokens[i]);
			print_string("\n");
		}
/*
	cmd = catcmd(paths, tokens);
	
	printf("%s\n", cmd);

	execve(cmd, tokens);
*/
		free(paths);
		free(tokens);	
		free(buffer);
	}

	return (0);
}
