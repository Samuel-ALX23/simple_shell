#include "shell.h"

/**
 * _strcmp - Function that compares two strings.
 * @str1: string pointer(1) to a constant character
 * @str2: string pointer(2) to a constant character
 *
 * Return: Always 0.
 */

int my_strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 < *str2)
		{
			return (-1);
		}
		else if (*str1 > *str2)
		{
			return (1);
		}

		str1++;
		str2++;
	}
	return (0);
}
