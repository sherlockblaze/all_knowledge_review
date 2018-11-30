#ifndef _REPLACE_ALL_SPACES_H_
#define _REPLACE_ALL_SPACES_H_

#define ElementType char

#include "../../data_structures/lists/arraylist.h"

void ReplaceAllSpaces(List List);
void TraverseList(List L);
void test();

#endif /*_REPLACE_ALL_SPACES_H_*/

void
ReplaceAllSpaces(List List)
{
	char Replace[] = {'0', '2', '%'};
	int SpaceCount = 0;
	int Size = List->Size;
	Array Array = List->ArrayList;
	for (int i = 0; i < List->Size; ++i)
		if (*(Array + i) == ' ')
			++SpaceCount;
	int NewSize = Size + 2 * SpaceCount;
	for (int i = Size, j = NewSize; i > -1; --i)
	{
		char Value = *(Array + i);
		if (Value != ' ')
		{
			*(Array + j) = Value;
			--j;
		}
		else
		{
			for (int k = 0; k < 3; ++k, --j)
				*(Array + j) = Replace[k];
		}
	}
	List->Size = NewSize;
}

void
TraverseList(List L)
{
	Array array = L->ArrayList;
	for (int i = 0; i < L->Size; ++i)
		printf("%c\t", *(array+i));
	printf("\n");
}

void
test()
{
	List List = NewList();
	char origin[] = {'a', 'b', ' ', 'c', ' ', ' ', 'd'};
	InsertArray(List, origin, 7);
	TraverseList(List);
	ReplaceAllSpaces(List);
	TraverseList(List);
}