#include <stdio.h>
#include "myerror.h"

void
FatalError(char *msg)
{
	printf("fatal error: %s\n", msg);
	exit(1);
}