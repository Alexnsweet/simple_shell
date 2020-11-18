#include "Header_shell.h"
/**
 * print_err - prints error
 * @str: error string message to print
 *
 * Return: write error return value
 */
int print_err(char *str)
{
	int i = 0;

	i = write(STDERR_FILENO, str, _strlen(str));

	return (i);
}
