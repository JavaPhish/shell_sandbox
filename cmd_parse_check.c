#include <stdio.h>
#include <stdlib.h>
#include "sandbox.h"

int main()
{
	char *cmd = "ls -l dynamic allocation is awful";
	char **cmd_list;
	int loop;

        cmd_list = cmd_parser(cmd);

	for (loop = 0; cmd_list[loop] != NULL; loop++)
	{
		printf("%s\n", cmd_list[loop]);
		free(cmd_list[loop]);
	}

	free(cmd_list);
	return (0);
}
