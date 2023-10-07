#include "shell.h"

/**
 * main - Entry point of the program
 *
 * Description: Tokenizes a given string using a delimiter
 * and prints each token on a new line.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char string[];
	char *index = NULL;
	char *delim = " \t";

	index = strtok(string, delim);
	while(index)
	{
		write(1, index, strlen(index));
		write(1, "\n", 1);

	}
	return (0);
}
