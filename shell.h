#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 10

int custom_strlen(const char *str);
int custom_strcmp(const char *str1, const char *str2);
void execute_command(char *command, char *args[]);
char *get_command_path(char *command);

#endif
