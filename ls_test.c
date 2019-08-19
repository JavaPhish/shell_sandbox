#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main( void )
{
    int status;
    char *args[2];

    args[0] = "/bin/ls";        // first arg is the full path to the executable
	args[1] = "-l";             // list of args must be NULL terminated
	args[2] = NULL;


        execve( args[0], args, NULL ); // child: call execv with the path and the args
    return 0;
}
