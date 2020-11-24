#include "Header_shell.c"
/**
 * _strncmp - compares two strings up to n chars
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: number of chars to compare
 *
 * Return: the difference in integer format
 */
int _strncmp(char *s1, char *s2, int n)
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
