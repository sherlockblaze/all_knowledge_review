#ifndef _SEARCH_IN_TWO_DIMENSIONAL_ARRAY_H_
#define _SEARCH_IN_TWO_DIMENSIONAL_ARRAY_H_

int IsExist(int *array, int rows, int columns, int value);
void Test();

#endif /*_SEARCH_IN_TWO_DIMENSIONAL_ARRAY_H_*/

#include <stdio.h>
#include <stdlib.h>

int
IsExist(int *array, int rows, int columns, int value)
{
	int j = columns - 1;
	int index, number;
	for (int i = 0; i < rows;)
	{
		index = i * columns + j;
		number = array[index];
		if (number == value)
			return 1;
		else if (number > value)
			--j;
		else
			++i;
		if (j < 0)
			break;
	}
	return 0;
}

void
Test()
{
	int array[] = {1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15};
	if (IsExist(array, 4, 4, 14))
		printf("true\n");
	else
		printf("false\n");
	if (IsExist(array, 4, 4, 8))
		printf("true\n");
	else
		printf("false\n");
}
