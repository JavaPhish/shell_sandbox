#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "sandbox.h"
#include <string.h>

int main(int argc, char *argv[], char *envp[])
{
	char *bin_path;
	int loop;
	(void)argc;
	(void)argv;

	for (loop = 0; envp[loop] != NULL; loop++)
	{
		if (_contains(envp[loop], "PATH")
			&& _contains(envp[loop], "_PATH") != 1
			&& _contains(envp[loop], "WPATH") != 1)
			{
				bin_path = malloc(sizeof(envp[loop] + 1));
				bin_path = envp[loop];
			}
	}

	printf("%s\n", bin_path);

	bin_path = strtok(bin_path, "=");
	bin_path = strtok(NULL, "=");

	printf("%s\n", bin_path);

	bin_path = strtok(bin_path, ":");
	printf("%s\n", bin_path);
	printf("%s\n", strtok(NULL, ":"));



	return 0;
}
