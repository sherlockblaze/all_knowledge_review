#ifndef _MYERROR_H_
#define _MYERROR_H_

void FatalError(char *msg);

#endif /* _Myerror_H */

void
FatalError(char *msg)
{
	printf("fatal error: %s\n", msg);
	exit(1);
}