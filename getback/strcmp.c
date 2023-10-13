#include "shell.h"

/**
 * check_strcp - Check and execute a command if it matches specific strings.
 * @tokens: An array of command arguments.
 * Description: This function checks the value of the first argument
 * to print environment variables.
 *
 * Return: 0 always(sucess)
 */


StructCommand execute_command[] = {

	{ "ls", "/bin/ls", NULL},
	{ "bin/ls", "bin/ls", NULL},
	{"ls -l", "/bin/ls", "-l"},
	{ "exit", NULL, NULL},
	{ "env", NULL, NULL},
};


int check_strcp(char **tokens)
{
	/*extern char **environ;*/
	int i = 0;

	for(i = 0; execute_command[i].code; i++)
	{
		if (strcmp(tokens[0], execute_command[i].code) == 0)
		{
			if(strcmp(tokens[0], "exit") == 0)
			{
			       freeus(tokens);	
				exit(0);
			}


			if (strcmp(tokens[0], "env") == 0)
			{
				env();
				freeus(tokens);
				return 0;
			}

			tokens[0] = execute_command[i].command;
			tokens[1] = execute_command[i].arg;
			tokens[2] = NULL;
			return 0;
			freeus(tokens);
		}
       }
	freeus(tokens);


	return (0);
}
