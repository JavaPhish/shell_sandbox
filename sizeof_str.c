#include <stdio.h>
#include <stdlib.h>

int sizeof_string(char *str)
{
	int size_counter;

	size_counter = 0;
	while(str[size_counter] != '\0')
		size_counter++;

	size_counter++;

	return (size_counter);
}
