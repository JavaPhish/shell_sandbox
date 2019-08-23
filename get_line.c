#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include  "sandbox.h"
#include <string.h>
/**
 *
 *
 *
 */
int main(int argc, char *argv[], char *envp[])
{
	char *buffer;
	char *copied_string;
	size_t buffer_size = 0;
	size_t chars_printed;
	char **env = envp_cpy(envp);

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
