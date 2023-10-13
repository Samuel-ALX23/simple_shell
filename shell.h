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


/*typedef struct {
        char *code;
        char *command;
        char *arg;
}StructCommand;*/


void freeus(char **tokens);
void env(void);
extern char **environ;
void procmd(char **args);
char *fetch_path(char *cmd);
/*char *tokenizer();
int check_strcp(char **args);
extern char **environ;
void env(void);*/

#endif

