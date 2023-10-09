#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

void exe_cmd(char **args);
char *fetch_path(char *sh);
char *tokenizer(char *command);
int check_variable(char **args);
extern char **environ;

#endif

