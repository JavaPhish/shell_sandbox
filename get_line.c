#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "sandbox.h"
#include <string.h>
/**
 *
 *
 *
 */
int main(int argc, char *argv[], char *envp[])
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	int chars_printed;
	char *cln_cmd;

	(void)argc;
	(void)argv;

	while (chars_printed != EOF)
	{
		write(1, "$ ", sizeof(char) * 2);
		chars_printed = getline(&buffer, &buffer_size, stdin);

		cln_cmd = strtok(buffer, "\n");


		/* Builtin handler returns one if it finds the builtin (And runs it)
		otherwise, execution is called */
		if (builtin_handler(cln_cmd, envp) != 1)
		{
			execution_handler(cln_cmd, envp_cpy(envp));
		}
	}

	free(buffer);
	return (0);
}
