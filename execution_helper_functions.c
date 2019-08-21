#include <stdio.h>
#include <stdlib.h>
#include "sandbox.h"
#include <string.h>

/**
 * find_path - Finds the full PATH variable and returns its contents
 * @env: The environment variables from main
 *
 * Return: The contents of PATH=
 */
char *find_path(char *env[])
{
	int loop;
	char *bin_path;

	if (!env)
		return (NULL);

        for (loop = 0; env[loop] != NULL; loop++)
        {
                if (_contains(env[loop], "PATH")
                        && _contains(env[loop], "_PATH") != 1
                        && _contains(env[loop], "WPATH") != 1)
                        {
                                bin_path = malloc(sizeof(env[loop]));
                                bin_path = env[loop];
                        }
        }

	bin_path = strtok(bin_path, "=");
	bin_path = _strdup(strtok(NULL, "="));

	return (bin_path);
}

/**
 * _contains - Checks if a string contains a given set of chars
 * @str: The string to check through
 * @keyword: The key word to check for
 *
 * Return: 1 if the keyword is in the string, 0 if not (Or edge case)
 */
int _contains(char *str, char *keyword)
{
	int loop, check_loop;

	check_loop = 0;

	if (str[0] == '\0')
		return (0);

	if (keyword[0] == '\0')
		return (0);

	if (!str)
		return (0);
	if (!keyword)
		return (0);

	for (loop = 0; str[loop] != '\0'; loop++)
	{
		if (keyword[check_loop] == '\0')
			return (1);

		if (str[loop] == keyword[check_loop])
			check_loop++;
		else
			check_loop = 0;


		if (str[loop + 1] == '\0' && keyword[check_loop] == '\0')
			return (1);
	}
	return (0);
}

/**
 * cmd_parser - seperates each parameter into a slot in an array
 * @cmd_to_parse: The command for parse (for ex. "Ls - l")
 *
 * Return: The 2d array for execution
 */
char **cmd_parser(char *cmd_to_parse)
{
	char **parsed_command;
	char *str_to_tok = _strdup(cmd_to_parse);
	char *counter = strtok(str_to_tok, " ");
	int loop;
	unsigned int max_byte_size = 0;

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
		return (NULL);

	strSize = 1;
	for (loop = 0; str[loop] != '\0'; loop++)
		strSize++;

	arr = malloc(strSize * (sizeof(char)));

	if (!arr)
		return (NULL);

	for (loop = 0; loop < strSize; loop++)
		arr[loop] = str[loop];

	return (arr);
}

/**
 * str_concat - Concatenates two strings into one
 * @s1: the first string
 * @s2: The second string
 *
 * Return: a pointer to the concatenated strings
 */
char *str_concat(char *s1, char *s2)
{
	int str1Size, str2Size, loop;
	char *arr;
	/**
	 * The first two arrays get the size of the two params
	 */
	str1Size = 0;
	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (s2 == NULL)
	{
		s2 = malloc(sizeof(char));
		s2[0] = '\0';
	}
	while (s1[str1Size] != '\0')
		str1Size++;
	str2Size = 0;
	while (s2[str2Size] != '\0')
		str2Size++;
	str2Size++;
	/*str2Size needs to be one extra to account for null byte*/
	arr = malloc((str1Size + str2Size) * sizeof(char));
	/* Makes sure theres enough memory*/
	if (!arr)
		return (NULL);
	for (loop = 0; loop < (str1Size + str2Size - 1); loop++)
	{
		if (loop > str1Size - 1)
			arr[loop] = s2[loop - str1Size];
		else
			arr[loop] = s1[loop];
	}
	return (arr);
}