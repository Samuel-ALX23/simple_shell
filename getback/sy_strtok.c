#include "shell.h"

/**
 * my_strtok - this program demonstrates the usage of the
 * strtok function to tokenize a string.
 * @str: a character string
 * @delim: The delimiter to use
 *
 *
 * Return: token always (sucess) or `NULL` if the end of the string is reached
 */

char *my_strtok(char *str, const char *delim)
{
	static char *saved_token;
	char *token_start;
	char *token_end;

	if (str != NULL)
	{
		token_start = str;
	}
	else
	{
		token_start = saved_token;
	}

	token_start += strspn(token_start, delim);

	if (*token_start == '\0')
	{
		saved_token = NULL;
		return (NULL);
	}

	token_end = strpbrk(token_start, delim);
	if (token_end != NULL)
	{
		*token_end = '\0';
		saved_token = token_end + 1;
	}
	else
	{
		saved_token = NULL;
	}

	return (token_start);
}
