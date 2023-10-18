#include "shell.h"

/**
 * my_strcmp - Function that compares two strings.
 * @str1: string pointer(1) to a constant character
 * @str2: string pointer(2) to a constant character
 *
 * Return: Always 0.
 */

int my_strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
