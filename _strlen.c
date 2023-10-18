#include "main.h"
/**
 * _strlen - counts string length
 * @s: input value
 *
 * Return: number of byte
 */
unsigned int  _strlen(char *s)
{
	int sum = 0;
	int i = 0;

	while (s[i] != '\0')
	{
		sum++;
		i++;
	}
	return (sum);
}
