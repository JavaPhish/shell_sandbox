#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "sandbox.h"
#include <string.h>

int main(int argc, char *argv, char *envp[])
{
	char *bin_path = find_path(envp);
	char *command = "ls";
	char **cmd_to_exec;
	char *temp;

	/*Voids argc since we have no need
	for the amount of arguments passed*/
	(void)argc;
	(void)argv;

	/*Calls a function which seperates the commands
	individual components into slots in an array.
	This is done for use in execve(filepath, command arguments)*/
	cmd_to_exec = cmd_parser(command);

	/*Attempts to execve with every file within the path
	once it find the correct one (Correct one being the one containing
	the requested command) it runs the command*/
	temp = strtok(bin_path, ":");
	while (temp != NULL)
	{
		execve(str_concat(temp, str_concat("/", cmd_to_exec[0])), cmd_to_exec, NULL);
		temp = strtok(NULL, ":");
	}

	return 0;
}
