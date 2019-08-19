#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "sandbox.h"
#include <string.h>

char **cmd_parser(char *cmd_to_parse);

int main(int argc, char *argv[], char *envp[])
{
	char *bin_path;
	int loop;
	char *command = "ls -l";
	char **cmd_to_exec;
	char *temp;

	(void)argc;
	(void)argv;
	/* Iterates through the environment variables in search of the
	PATH where the shell stuff is kept */
	for (loop = 0; envp[loop] != NULL; loop++)
	{
		if (_contains(envp[loop], "PATH")
			&& _contains(envp[loop], "_PATH") != 1
			&& _contains(envp[loop], "WPATH") != 1)
			{
				bin_path = malloc(sizeof(envp[loop] ));
				bin_path = envp[loop];
			}
	}

	/* This line just removes the "PATH=" from the bin_path
	it should now look like this bin/... rather than "PATH=bin/... */
	bin_path = strtok(bin_path, "=");
	bin_path = strtok(NULL, "=");

	/* This sets bin path to the first
	path to attempt to execute from */
	temp = strtok(bin_path, ":");

	cmd_to_exec = cmd_parser(command);

	loop = 0;
	while (temp != NULL)
	{
		printf("%s\n", temp);
		strtok(NULL, ":");
	}

/*	while (bin_path != NULL)
	{
		printf("%s\n", str_concat(bin_path, str_concat("/", cmd_to_exec[0])));
		execve(str_concat(bin_path, str_concat("/", cmd_to_exec[0])), cmd_to_exec, NULL);
		free(bin_path);
		bin_path = malloc(sizeof(strtok(NULL, ":")));
		printf("%s\n", bin_path);

	} */
	return 0;
}

/**
 * cmd_parser - Seperates one string into different commands for use in execvp
 * @cmd_to_parse: THe command to be parsed
 *
 * Return: The new array (Generally for execution)
 */
char **cmd_parser(char *cmd_to_parse)
{
	char **parsed_command = malloc(8 * sizeof(char *));
	char *temp = strtok(cmd_to_parse, " ");
	int loop = 0;

	/* This loops through the given command and separates
	each command or parameter using strtok. Each seperate
	parameter or command is put into its own slot in the
	array */
	while (temp != NULL)
	{
		parsed_command[loop] = temp;

		loop++;

		temp = strtok(NULL, " ");
	}

	/* Null terminated last slot in the array */
	parsed_command[loop] = NULL;

	return (parsed_command);
}

