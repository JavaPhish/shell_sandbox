#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "sandbox.h"

int main(int argc, char *argv[], char *envp[])
{
	char *buffer = NULL;
	char *strtok_address;
	size_t buffer_size = 0;
	int chars_printed = 0;
	(void)argc;
	(void)argv;

	while (chars_printed != EOF)
	{
		write(1, "$ ", sizeof(char) * 2);
		chars_printed = getline(&buffer, &buffer_size, stdin);
		strtok_address = buffer;
		buffer = strtok(buffer, "\n");

		if (buffer != NULL)
			write(1, buffer, sizeof_string(buffer));
		write(1, "\n", sizeof("\n"));

		if (builtin_handler(buffer, envp) == 0)
		{
			/*
			 *If builtin handler returns 0, it did not find
			 *a builtin function by the provided name. So now
			 *we will attempt to execute it as an executable.
			*/

			execution_handler(buffer, envp);

		}
	}

	free(strtok_address);

	return (1);
}
