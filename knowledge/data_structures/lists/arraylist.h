#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

#define ElementType int

typedef ElementType *PtrToArray;
typedef PtrToArray Array;
typedef struct HeadNode *PtrToHeadNode;
typedef PtrToHeadNode List;

List NewList();
List NewListWithLength(int capacity);
void Insert(List L, ElementType value);
void InsertAt(List L, int index, ElementType value)
void IncreaseCapacity(List L);
void TraverseList(List L);

#endif /*_ARRAYLIST_H_*/

#include <stdio.h>
#include <stdlib.h>

struct HeadNode
{
	ElementType* ArrayList;
	int Size;
	int Capacity;
};

// Default capacity is 10
List
NewList()
{
	return NewListWithLength(10);
}

List
NewListWithLength(int capacity)
{
	List list;
	Array array;
	array = (ElementType *)malloc(sizeof(ElementType) * capacity);
	list = (struct HeadNode *)malloc(sizeof(struct HeadNode) * capacity);
	if (array == NULL || list == NULL)
		FatalError("No Enough Room!!");
	list->ArrayList = array;
	list->Size = 0;
	list->Capacity = 10;
	return list;
}

void
Insert(List L, ElementType value)
{
	Array array;
	if (L->Size >= L->Capacity)
		IncreaseCapacity(L);
	array = L->ArrayList;
	*(array + size) = value;
	L->Size += 1;
}

void
InsertAt(List L, int index, ElementType value)
{
	if (index == L->Size - 1)
		
}

void 
IncreaseCapacity(List L)
{
	Array array;
	int Capacity = L->Capacity;
	int NewCapacity = Capacity / 2 * 3 + Capacity;
	array = (ElementType *)malloc(sizeof(ElementType) * NewCapacity);
	if (array == NULL)
		FatalError("No Enough Room!!");
	for (int i = 0; i < L->Size; ++i)
	{
		*(array + i) = *(L->ArrayList + i);
	}
	L->ArrayList = array;
	L->Capacity = NewCapacity;
}

void
TraverseList(List L)
{
	Array array = L->ArrayList;
	for (int i = 0; i < L->Size; ++i)
		printf("%d\t", *(array+i));
	printf("\n");
}

void
ArrayListTest()
{
	List list;
	list = NewList();
	list->ArrayList[0] = 11;
	list->ArrayList[1] = 12;
	list->Size = 2;
	TraverseList(list);
	printf("%d\n", list->Capacity);
	printf("%d\n", list->ArrayList);
	IncreaseCapacity(list);
	TraverseList(list);
	printf("%d\n", list->ArrayList);
	printf("%d\n", list->Capacity);
	printf("%d\n", list->ArrayList[0]);
	printf("%d\t%d\t%d\n", sizeof(list), sizeof(int), sizeof(ElementType));
	IncreaseCapacity(list);
}