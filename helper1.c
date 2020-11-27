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

/**
 * _ttyprompt - writes specified prompt and specifies if a tty or not
 *
 * Return: 1 if is a tty or 0 if not
 */
int _ttyprompt(void)
{
	int tty;

	if (isatty(STDIN_FILENO))
	{	write(STDOUT_FILENO, "($) ", 4);
		tty = 1;
	}
	else if (isatty(STDIN_FILENO) != 1)
	{
		tty = 0;
	}

	return (tty);
}

/**
 * isbuiltin - checks line input to see if it's a builtin command
 * @paths: array of char pointers to tokenized path values
 * @tokens: tokenized line arguments
 * @buffer: line argument
 * @path: path to free
 *
 * Return: 0 if not a builtin or 2 if builtin
 */
int isbuiltin(char **paths, char **tokens, char *buffer, char *path)
{
	int i;

	if (_strcmp(tokens[0], "exit") == 0)
	{
		free(paths);
		free(path);
		free(tokens);
		free(buffer);
		_exit(0);
	}
	else if (_strcmp(tokens[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{

			print_string(environ[i]);
			print_string("\n");
		}
		return (2);
	}

		return (0);
}
