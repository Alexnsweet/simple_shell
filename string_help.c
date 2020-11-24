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

/**
 * _strdup - returns pointer to new alloc'd space in mem containing string
 * @str: string to duplicate
 *
 * Return: NULL if string is NULL or pointer to new string
 */


/*
char *_strdup(char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
	{	return (NULL);	}
	else
	{	for (len = 0; *(str + len) != '\0'; len++)
		;
	}

	ptr = malloc(sizeof(char) * (len + 1));

	if (ptr == NULL)
	{	return (NULL);	}

	for (i = 0; str[i] != '\0'; i++)
	{	ptr[i] = str[i];	}

	ptr[i] = '\0';

	return (ptr);
}
*/

char *_strdup(char *str)
{
	char *ar;
	unsigned int i, size;

	if (str == NULL)
		return (NULL);
	for (size = 0; *(str + size) != '\0'; size++)
		;
	ar = (char *) malloc((size + 1) * sizeof(char));
	if (ar == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		ar[i] = str[i];
	}
	ar[i] = '\0';
	return (ar);
}



/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: 0 if same or < > if s1 or s2 is less or greater
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
		{
		return (0);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * tokenizer - returns a NULL terminated array of string pointers
 * @str: string to tokenize
 * @delim: delimeter
 *
 * Return: NULL terminated array of string pointers to tokens
 */
char **tokenizer(char *str, char *delim)
{
	char **buffer;
	int delim_count = 0, i, token_count;

	for (i = 0; str[i] != '\0'; i++)
	{	if (str[i] == *delim)
		{	delim_count++;	}
	}

	token_count = delim_count + 1;

	buffer = malloc(sizeof(char *) * (token_count + 1));

	if (buffer == NULL)
	{	return (NULL);	}

	i = 0;
	buffer[i] = strtok(str, delim);
	i++;
	while (i < token_count)
	{
		buffer[i] = strtok(NULL, delim);
		i++;
         }
	buffer[i] = NULL;
	return (buffer);
}
