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
void IncreaseCapacity(List L);
void TraverseList(List L);

#endif /*_ARRAYLIST_H_*/

#include <stdio.h>
#include <stdlib.h>

struct HeadNode
{
	ElementType* List;
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
	list->List = array;
	list->Size = 0;
	list->Capacity = 10;
	return list;
}

void
Insert(List L, ElementType value)
{
	if (L->Size < L->Capacity)
	{

	}
}

void 
IncreaseCapacity(List L)
{
	Array array;
	int Capacity = L->Capacity;
	int NewCapacity = Capacity / 2 * 3 + Capacity;
	array = (ElementType *)malloc(sizeof(ElementType) * NewCapacity);
	
}

void Travese

void
ArrayListTest()
{
	List list;
	list = NewList();
	list->List[0] = 11;
	list->List[1] = 12;
	printf("%d\n", list->List[0]);
	printf("%d\t%d\t%d\n", sizeof(list), sizeof(int), sizeof(ElementType));
	IncreaseCapacity(list);
}