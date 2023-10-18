#include "shell.h"

/**
 * @src: The constant character string to duplicate
 * Description: A function that duplicates strings
 *
 * Return: targ always (sucess) or `NULL` if there is an error
 */

char* my_strdup(const char * src)
{
	int i;
	int src_len = 0;
	char * targ = NULL;

	if (src == NULL)
	{
		return (NULL);
	}

	while (src[src_len] != '\0')
	{
		src_len++;
	}

	targ = malloc(src_len + 1);
	if (targ == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < src_len; i++)
	{
		targ[i] = src[i];
	}

	targ[src_len] = '\0';

	return (targ);
}
