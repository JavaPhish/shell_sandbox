#include <stdio.h>
#include <stdlib.h>
#include "sandbox.h"

int main()
{
	char *cmd = "ls -l";
	char **cmd_list;
	int loop;
	int height;

        cmd_list = cmd_parser(cmd);

	for (loop = 0; cmd_list[loop] != NULL; loop++)
		printf("%s\n", cmd_list[loop]);

	height = loop;

	for (loop = 0; loop < height; loop++)
		free(cmd_list[loop]);

	free(cmd_list);
	return (0);
}
