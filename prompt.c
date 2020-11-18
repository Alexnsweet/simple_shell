#include "Header_shell.h"

int main(int ac, char **av)
{
	char prompt[] = "$ ";
	char *buffer;
	size_t buffSize = 0;
	int gl;
	(void)ac;

	av[0] = prompt;
	print_string(prompt);

	gl = getline(&buffer, &buffSize, stdin);
	if (gl == -1)
	{	print_err("could not read line");
		return (-1);
	}
	else
	{
		print_string(buffer);
		free(buffer);
		return (0);
	}
}
