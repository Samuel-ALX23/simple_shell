#include "main.h"
/**
 * main - int main
 * Return: NULL
 */
int main(void);
int main(void)
{
	char *buff = NULL;
	size_t n = 0;
	int num;
	pid_t pid;
	int status;
	char *token;
	int i = 0;
	char *args[8000] = {NULL};

	while (1)
	{

		/*display();*/
		num = getline(&buff, &n, stdin);
		if (num == -1)
		{
			break;
		}
		if (_strlen(buff) > 1)
		{
			token  = strtok(buff, " \n\t\r");
			while (token)
			{
				args[i] = token;
				token = strtok(NULL, " \n\t\r");
				i++;
			}
			args[i] = NULL;
			i = 0;
			if (args[0] == NULL)
				continue;
			if (strcmp(args[0], "exit") == 0)
			{
				break;
			}
			if (strcmp(args[0], "env") == 0)
			{
				while (environ[i])
				{
					printout(environ[i]);
					printout("\n");
					i++;
				}
				i = 0;
				continue;
			}
			pid = fork();
			if (pid == 0)
			{
				if (strcmp(args[0], "ls") == 0)
				{
				execve("/bin/ls", args, environ);
				}
				else
				{
					 execve(args[0], args, environ);
				}
				perror("./a.out");
				exit(EXIT_FAILURE);
			}
			else if (pid < 0)
			{
				perror("./a.out");
			}
			else
			{
				wait(&status);
			}
		}
	}

	free(buff);
	return (0);
}
