#include <stdio.h>
#include <stdlib.h>
#include "./lists/linkedlist.h"


int
main()
{
	List list = NewList();
	printf("%d\n", IsEmpty(list));
	printf("%d\n", Insert(list, 1));
	printf("%d\n", Insert(list, 25));
	int values[5] = {1, 2, 3, 4, 5};
	printf("%d\n", InsertArray(list, values, 5));
	TraverseList(list);
	return 0;
}
