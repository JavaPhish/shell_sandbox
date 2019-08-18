#include <stdio.h>
#include <stdlib.h>
#include "sandbox.h"

int main()
{
	printf("%d\n", _contains("test phrase", "test phrase"));
	printf("%d\n", _contains("Penis", "enis"));
	printf("%d\n", _contains("test", "p"));


	return (0);
}

