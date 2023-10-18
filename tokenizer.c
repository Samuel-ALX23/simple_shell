#include "main.h"
/**
 * tokenizer - tokenize string
 * @buff: string
 * Return: args
 */
char **tokenizer(char *buff)
{
	char *del = " \n\t";
	char *token = strtok(buff, del);
	static char *argx[12000] = {NULL};
	int j = 0;

	while (token != NULL)
	{
		argx[j] = token;
		token = strtok(NULL, del);
		j++;
	}
	argx[j] = NULL;
	return (argx);



}
