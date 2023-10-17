#include "shell.h"

/**
 * @str: The string to tokenize
 * @delim: The delimiter to use
 * Description: A function that  Tokenizes the string `str` using the delimiter `delim`
 *
 * Return: token always (sucess) or `NULL` if the end of the string is reached
 */

char* my_strtok(char * str, const char * delim)
{
	char * token = str;
	char * next_delim = strchr(token, * delim);

	if (str == NULL)
	{
		return (NULL);
	}

	if (delim == NULL)
	{
		return (NULL);
	}

	while (* token != '\0' && strchr(delim, * token) != NULL)
	{
		token++;
	}

	if (* token == '\0')
	{
		return (NULL);
	}

	if (next_delim != NULL)
	{
		* next_delim = '\0';
		str = next_delim + 1;
	}

	return (token);
}
