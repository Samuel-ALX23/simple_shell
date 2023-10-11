#include "shell.h"
/**
 *
 *
 *
 *
 */
void env(void)
{
	int i = 0;

	i = 0;
                while(environ[i])
                {
                        write(1, environ[i], strlen(environ[i]));
                        write(1, "\n", 1);
                        i++;
                }

}
