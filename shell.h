#ifndef SHELL_H
#define SHELL_H


#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <signal.h>

<<<<<<< HEAD
/*int main(int ac, char **av, char **env);*/
char **tokenize(char *command, char *delim);
/*char *_getenv(const char *name);
=======
void _write(char *str, int stm);

int main(int ac, char **av, char **env);
char *_getenv(const char *name);
>>>>>>> e46a7f6fbe5de346d07d3d6445e8825f72748582
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);*/

#endif
