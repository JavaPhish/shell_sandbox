#include        <stdio.h>
#include        <stdlib.h>
#include        <unistd.h>
#include        <string.h>
#include        <errno.h>

int     main()
{
  int e;
  char *envp[] = { NULL };
  char *argv[] = { "/usr/bin/ls", "-l", NULL };

  e = execve(argv[0], argv, NULL);
  if (e == -1)
      fprintf(stderr, "Error: %s\n", strerror(errno));
  return 0;
}
