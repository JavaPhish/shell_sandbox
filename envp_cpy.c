#include <stdio.h>
#include <stdlib.h>
#include "sandbox.h"

/**
 * envp_cpy - Creates a duplicate of the original environment Vars
 * @envp: The original envp
 *
 * Return: The new envp to be parsed through
 */
char **envp_cpy(char *envp[])
{
	char **copied_envp;
	int row_count, char_alloc;

	row_count = 0;
	while (envp[row_count] != NULL)
		row_count++;

	copied_envp = malloc(sizeof(char *) * row_count);

	char_alloc = 0;
	while (envp[char_alloc] != NULL)
	{
		copied_envp[char_alloc] = malloc(sizeof_string(envp[char_alloc]));
		_strcpy(copied_envp[char_alloc], envp[char_alloc]);
		char_alloc++;
	}

	return (copied_envp);

}
