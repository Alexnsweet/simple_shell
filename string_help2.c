#include "Header_shell.h"
/**
 * _strncmp - compares two strings up to n chars
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: number of chars to compare
 *
 * Return: the difference in integer format
 */
int _strncmp(char *s1, char *s2, size_t n)
{
        int i = 0;

        while (s1[i] == s2[i] && i < n)
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
