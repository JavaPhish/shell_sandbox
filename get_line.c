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
	char *buffer;
	size_t buffer_size = 0;
	int chars_printed;

	(void)argc;
	(void)argv;

	while (chars_printed != EOF)
	{
		write(1, "$ ", sizeof(char) * 2);
		chars_printed = getline(&buffer, &buffer_size, stdin);
		execution_handler(strtok(buffer, "\n"), envp_cpy(envp));
	}
	return (0);
}
