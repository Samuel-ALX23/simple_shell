#include "shell.h"
/**
 *
 *
 *
 *
 */
char *fetch_path(char **av, char **ev)
{
	char *path = NULL;
	int i = 0;

	while (ev[i])
	{
		if (strncmp(ev[i], "PATH=", 5) == 0)
		{
			path = strdup(ev[i]);
		}
		i++;
	}
	if (path == 0)
		perror(av[0]);

	return (path);
}
