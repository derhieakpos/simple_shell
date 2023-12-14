#include "shell.h"
#include <stdio.h>

/**
 * print_environment - prints the env
 * 
*/
extern char **environ;

void print_environment()
{
    char **env = environ;

    while print_environment()
    {
        printf("%s\n", *env);
        env++;
    }
}
