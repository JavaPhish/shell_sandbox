#include <stdio.h>
#include <stdlib.h>
#include "sandbox.h"

int main(int argc, char *argv[], char *envp[])
{

	char **new_env;
	int loop;

	(void)argc;
	(void)argv;

	new_env = envp_cpy(envp);

	loop = 0;
	while (new_env[loop] != NULL)
	{
		printf("%s\n", new_env[loop]);
		free(new_env[loop]);
		loop++;
	}

	free(new_env);

	return (0);
}
