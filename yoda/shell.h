#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

void freeus(char **tokens);
void env(void);
extern char **environ;
void procmd(char **args, char *cmd);
char *fetch_path(char *cmd);

char *my_strtok(char *str, const char *delim);
size_t my_strlen(const char *str);
int my_strcmp(const char *str1, const char *str2);
ssize_t my_write(int fd, const void *buf, size_t count);

#endif

