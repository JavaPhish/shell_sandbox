#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "sandbox.h"

/**
 * main - contains the loop and input handler for the rest of the shell
 * @argc: Casted to void(Unused)
 * @argv: Casted to void(Unused)
 * @envp: Used to find the path containing system commands
 *
 * Return: 1 on success, 0 on screw up
 */
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
		{
			if (builtin_handler(buffer, envp) == 0)
			{
				execution_handler(buffer, envp);
			}
		}
	}
	free(strtok_address);

	return (1);
}
