#include "shell.h"

/**
 * fetch_path: Fetches the absolute path of a command
 * @cmd: The command to fetch the path for
 *
 * Return: The absolute path of the command if found, otherwise NULL
 */

char *fetch_path(char *cmd);
char *fetch_path(char *cmd)
{
	char *path = NULL;
	/*char *double_path = NULL;*/
	char *tokpath = NULL;
	char *filepath = NULL;
	int dir_len = 0;
	int cmd_len = 0;
	struct stat buf;


	path = getenv("PATH");
	cmd = strtok(cmd, " \n\t\r");


	if (path)
	{	if(strchr(cmd, '/') != NULL)
		{
			return (cmd);
		}
<<<<<<<< HEAD:shell/shell-loc_funx/path.c
		/*double_path = strdup(path);*/
	/*	cmd_len = strlen(cmd);

		tokpath = strtok(path, ":");
========
		double_path = my_strdup(path);
		cmd_len = my_strlen(cmd);
>>>>>>>> 42e538268198e44c8550bf289bc7b8b08dd47f03:shell/path.c

		tokpath = my_strtok(double_path, ":");

		while(tokpath)
		{
			dir_len = my_strlen(tokpath);
			filepath = malloc(cmd_len + dir_len + 2);
			my_strcpy(filepath, tokpath);
			my_strcat(filepath, "/");
			my_strcat(filepath, cmd);
			my_strcat(filepath, "\0");

			if (stat(filepath, &buf) == 0)
			{
				
				free(double_path);
				return (filepath);
			}
			else
			{
				free(filepath);
				tokpath = my_strtok(NULL, ":");
			}
		}
		free(double_path);
		if (stat(cmd, &buf) == 0)
		{
			return (cmd);
		}
<<<<<<<< HEAD:shell/shell-loc_funx/path.c
		return (NULL);*/

========
		return (NULL);
>>>>>>>> 42e538268198e44c8550bf289bc7b8b08dd47f03:shell/path.c
	}
	return (NULL);
}
