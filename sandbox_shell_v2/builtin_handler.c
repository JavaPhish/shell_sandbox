#include <stdio.h>
#include <stdlib.h>
#include "sandbox.h"
#include <string.h>
#include <unistd.h>

int print_env(char *envp[]);

int builtin_handler(char *cmd, char *envp[])
{
        if (_strcmp(cmd, "env") == 0)
        {
                print_env(envp);
                return (1);
        }

	if (_strcmp(cmd, "exit") == 0)
		exit(1);

        return (0);
}

int print_env(char *envp[])
{
        int loop;

        loop = 0;
        while (envp[loop] != NULL)
        {
                write(1, envp[loop], sizeof_string(envp[loop]));
                write(1, "\n", 1);
                loop++;
        }

        return (1);
}

