#include "Header_shell.h"
/**
 * _strncmp - compares two strings up to n chars
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: number of chars to compare
 *
 * Return: the difference in integer format
 */
int _strncmp(char *s1, char *s2, ssize_t n)
{
	while (*s1 == *s2 && n--)
	{
		s1++;
		s2++;
	}
	if (n)
	{	return (*s1 - *s2);	}
	return (0);
}

/**
 * _strcat - concatenates 2 strings
 * @dest: destination string
 * @src: source string
 *
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int dest_len = 0, i, j;

	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	for (j = 0, i = 0; src[j] != '\0'; i++, j++)
	{
		dest[dest_len + i] = src[j];
	}
	dest[dest_len + i] = '\0';

	return (dest);

}

/**
 * concat - mallocs space for command string and concatenates strings
 * @str: string
 * @str2: string to append to str1
 *
 * Return: string pointer to malloc'd concatenated string
 */
char *concat(char *str, char *str2)
{
	char *cat;
	int size;

	size = (_strlen(str) + _strlen(str2) + 2);

	cat = malloc(sizeof(char) * size);
	cat = _strcpy(cat, str);
	cat = _strcat(cat, "/");
	cat = _strcat(cat, str2);

	return (cat);
}

/**
 * _strcpy - function that copies string from src to dest
 * @dest: destination
 * @src: source
 *
 * Return: char array (string)
 */
char *_strcpy(char *dest, char *src)
{
	int i, len = 0;

while (src[len] != '\0')
{
	len++;
}

for (i = 0; i <= len; i++)
{
	dest[i] = src[i];
}

	return (dest);
}
