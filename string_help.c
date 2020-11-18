#include "Header_shell.h"

/**
 * _strlen - Counts the number of chars in a string
 * @s: string to count
 *
 * Return: number of characters in a string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{	i++;	}

	return (i);
}

/**
 * print_string - writes number of chars in string
 * @str: string to print
 *
 * Return: -1 if error (errno is set) or # of bytes written on success
 */
int print_string(char *str)
{
	int i = 0;

	i = write(1, str, _strlen(str));

	return (i);
}
