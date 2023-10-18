#include "shell.h"

/**
 * my_getenv - Retrieve the value of an environment variable.
 * @varname: The name of the environment variable.
 *
 * Return: Null always (success)
 */

char *my_getenv(const char *varname)
{
	size_t varname_len = my_strlen(varname);

	if (varname == NULL || environ == NULL)
	{
		return (NULL);
	}

	for (char **env = environ; *env != NULL; env++)
	{
		if (strncmp(varname, *env, varname_len) == 0 && (*env)[varname_len] == '=')
		{
			return (&((*env)[varname_len + 1]));
		}
	}

	return (NULL);
}
