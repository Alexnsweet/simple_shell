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
	char *ptr = NULL, *ptr2 = NULL;

	k = _strlen(*envvar);

	for (i = 0, j = 0, k = 0; environ[i]; i++)
	{
		j = _strncmp(environ[i], *envvar, k);

		if (j == 0)
		{	ptr = &environ[i][k]; /* return string after =  */
			return (ptr);
		}
	}
	print_string("could not find variable");
	return (ptr);
}	
	
