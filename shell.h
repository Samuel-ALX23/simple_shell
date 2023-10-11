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

void freeus(char **tokens);
void exe_process(char **args);
/*char *fetch_path(char **av, char **en);*/
char *tokenizer();
int check_strcp(char **args);
extern char **environ;
void env(void);

#endif

