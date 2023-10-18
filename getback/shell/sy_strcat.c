#include "shell.h"

/**
 * @targ: Target string
 * @src: The source string pointer to constant string
 * Description: The function modifies the destination string that is passed to it
 *
 * Return: targ always (sucess)
 */

char * my_strcat(char * targ, const char * src)
{
	int targ_len = 0;
	int i = 0;
	int src_len = 0;


	if (targ == NULL)
	{
		return (NULL);
	}

	while (targ[targ_len] != '\0')
	{
		targ_len++;
	}

	while (src[src_len] != '\0')
	{
		src_len++;
	}

	targ = realloc(targ, targ_len + src_len + 1);
	if (targ == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < src_len; i++)
	{
		targ[targ_len + i] = src[i];
	}

	targ[targ_len + src_len] = '\0';

	return (targ);
}
