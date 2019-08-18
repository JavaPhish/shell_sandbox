#include <stdio.h>
#include <unistd.h>

/**
 * main - PID The parent process of the process that created it
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;

    my_pid = getppid();
    printf("%u\n", my_pid);
    return (0);
}
