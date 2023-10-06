#include "shell.h"
/**
 *
 *
 *
 */
int main(void)
{
	char string[] = "Sammy, we will surely overcome simple shell";
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
