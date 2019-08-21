#include <stdio.h>
#include <stdlib.h>
#include "sandbox.h"
#include <string.h>

char **cmd_parser(char *cmd_to_parse)
{
	char **parsed_command;
	char *str_to_tok = _strdup(cmd_to_parse);
	char *counter = strtok(str_to_tok, " ");
	char *temp;
	int loop, alloc_loop;
	int max_byte_size = 0;

	str_to_tok = _strdup(cmd_to_parse);
	temp = str_to_tok;

	/* Determines the amount of slots needed to allocate in the 2d Array*/
	for (loop = 0; counter != NULL; loop++)
	{
		counter = strtok(NULL, " ");
		if (sizeof(counter) > max_byte_size)
			max_byte_size = sizeof(counter);
	}

	parsed_command = malloc(loop * max_byte_size);

	counter = _strdup(cmd_to_parse);
	counter = strtok(counter, " ");
	for (loop = 0; counter != NULL; loop++)
	{
		parsed_command[loop] = counter;
		counter = strtok(NULL, " ");
	}
	parsed_command[loop] = NULL;

	free(counter);
	free(str_to_tok);
	return (parsed_command);
}

/**
 * _strdup - Duplicates a string using malloc
 * @str: the string to duplicate
 *
 * Return: a pointer to the string
 */
char *_strdup(char *str)
{
	int loop, strSize;
	char *arr;

	if (str == NULL)
	{
		return (NULL);
	}



	strSize = 1;
	for (loop = 0; str[loop] != '\0'; loop++)
	{
		strSize++;
	}

	arr = malloc(strSize * (sizeof(char)));

	if (!arr)
	{
		return (NULL);
	}

	for (loop = 0; loop < strSize; loop++)
	{
		arr[loop] = str[loop];
	}

	return (arr);

}
