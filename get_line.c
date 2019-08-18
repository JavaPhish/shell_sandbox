#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 *
 *
 *
 */
int main(void)
{
	char *buffer;
	size_t buffer_size = 0;
	size_t chars_printed;


	while (chars_printed != EOF)
	{

		write(1, "$ ", sizeof(char) * 2);
		chars_printed = getline(&buffer, &buffer_size, stdin);
		write(1, buffer, sizeof(buffer));

	}
	return (0);
}
