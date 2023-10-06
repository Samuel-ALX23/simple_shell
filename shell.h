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

/*int main(int ac, char **av, char **env);*/
char **tokenize(char *command, char *delim);
void _write(char *str, int stm);
char *_strncat(char *dest, char *src, int n);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);

/*char *_getenv(const char *name);
void _write(char *str, int stm);

int main(int ac, char **av, char **env);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);*/

#endif
