#include <stdio.h>
#include <stdlib.h>
#include "sandbox.h"
#include <string.h>
#include <unistd.h>

int print_env(char *envp[]);

int builtin_handler(char *cmd, char *envp[])
{

	printf("%s\n", cmd);
	if (_strcmp(cmd, "env") == 0)
	{
		print_env(envp);
		return (1);
	}

	return (0);
}



int print_env(char *envp[])
{
	int loop;

	loop = 0;
	while (envp[loop] != NULL)
	{
		printf("%s\n", envp[loop]);
		loop++;
	}

	return (1);

}
