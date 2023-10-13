#include "shell.h"
/**
 *
 *
 *
 *
 *
 *
 */
char *fetch_path(char *cmd)
{
	char *path = NULL;
	char *double_path = NULL;
	char *tokpath = NULL;
	char *filepath = NULL;
	int dir_len = 0;
	int cmd_len = 0;
	struct stat buf;

	path = getenv("PATH");
	if(path)
	{
		double_path = strdup(path);
		cmd_len = strlen(cmd);

		tokpath = strtok(double_path, ":");

		while(tokpath)
		{
			dir_len = strlen(tokpath);
			filepath = malloc(cmd_len + dir_len + 2);
			strcpy(filepath, tokpath);
			strcat(filepath, "/");	      
			strcat(filepath, cmd);
			strcat(filepath, "\0");

			if(stat(filepath, &buf) == 0)
			{
				free(double_path);
				return(filepath);
			}
			else
			{
				free(filepath);
				tokpath = strtok(NULL, ":");
			}		

		}
		free(double_path);
		if(stat(cmd, &buf) == 0)
		{
			return(cmd);
		}
		return(NULL);

	}
	return(NULL);
}
