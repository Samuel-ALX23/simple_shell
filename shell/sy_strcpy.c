#include "shell.h"

/**
 * @param targ: The destination string.
 * @param src: The source string.
 * @Description: Copies the string `src` to the string `targ`
 *
 * Return: targ always(sucess)
 */


char* my_strcpy(char* targ, const char* src)
{
	int src_len = 0;
	int i;

	if (targ == NULL)
	{
		return (NULL);
	}

	while (src[src_len] != '\0')
	{
		src_len++;
	}

	targ = realloc(targ, src_len + 1);
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
