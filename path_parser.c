#include "Header_shell.h"

/**
 * path_parser - searches for n byes of env variable and returns values
 * @envvar: name of environment variable to search for
 *
 * Return: string of values for environment variable
 */
char *path_parser(char *envvar)
{
	int i, j, k;
	char *ptr = NULL;

	k = _strlen(envvar);

	for (i = 0, j = 0; environ[i]; i++)
	{
		j = _strncmp(environ[i], envvar, k);

	/*	printf("I is [%d] J is [%d] K is [%d] \n", i, j, k); */

		if (j == 0)
		{	ptr = _strdup(&environ[i][k]); /* return string after =  */
			return (ptr);
		}
	}
	print_string("could not find variable");
	return (ptr);
}
