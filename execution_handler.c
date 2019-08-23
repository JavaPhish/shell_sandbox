#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "sandbox.h"
#include <string.h>

/**
 * execution_handler - Executes the given command
 * @raw_cmd: The command passed on by the user (not ready for execve)
 * @envp: The environment variable from origin main
 *
 * Return: 1 on success, 0 if failure;
 */
int execution_handler(char *raw_cmd, char **env)
{
	char *bin_path = find_path(env);
	char *executable_command;
	char **cmd_to_exec;
	char *temp;

	printf("%s\n", bin_path);
	/*Calls a function which seperates the commands
	individual components into slots in an array.
	This is done for use in execve(filepath, command arguments)*/
	cmd_to_exec = envp_cpy(cmd_parser(raw_cmd));

	/*Attempts to execve with every file within the path
	once it find the correct one (Correct one being the one containing
	the requested command) it runs the command*/
	temp = strtok(bin_path, ":");
	while (temp != NULL)
	{
		executable_command = str_concat(temp, str_concat("/", cmd_to_exec[0]));

		if (access(executable_command, F_OK) == 0)
		{
			execve(executable_command, cmd_to_exec, NULL);
		}

		temp = strtok(NULL, ":");
	}

	return 0;
}
