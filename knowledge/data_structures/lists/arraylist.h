#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

#define ElementType int

typedef ElementType *PtrToArray;
typedef PtrToArray Array;
typedef struct HeadNode *PtrToHeadNode;
typedef PtrToHeadNode List;

List NewList();
List NewListWithCapacity(int capacity);
void Insert(List L, ElementType value);
void InsertAt(List L, int index, ElementType value);
void InsertArray(List L, ElementType* array, int length);
void Delete(List L);
void DeleteAt(List L, int index);
ElementType Retrieve(List L, int index);
void IncreaseCapacity(List L);
void MoveTheValuesBackwards(List L, int index);
void MoveTheValuesForWard(List L, int index);
void TraverseList(List L);
void DeleteArrayList(Array array, int capacity);

#endif /*_ARRAYLIST_H_*/

#include <stdio.h>
#include <stdlib.h>
#include "../errors/myerror.h"

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
	return NewListWithCapacity(10);
}

List
NewListWithCapacity(int capacity)
{
	List list;
	Array array;
	array = (ElementType *)malloc(sizeof(ElementType) * capacity);
	list = (struct HeadNode *)malloc(sizeof(struct HeadNode) * capacity);
	if (array == NULL || list == NULL)
		FatalError("No Enough Room!!");
	list->ArrayList = array;
	list->Size = 0;
	list->Capacity = capacity;
	return list;
}

void
Insert(List L, ElementType value)
{
	Array array;
	if (L->Size >= L->Capacity)
		IncreaseCapacity(L);
	array = L->ArrayList;
	*(array + L->Size) = value;
	L->Size += 1;
}

void
InsertAt(List L, int index, ElementType value)
{
	Array array;
	if (index > L->Size)
		FatalError("Insert Failed. Illegal index.");
	if (L->Size + 1 > L->Capacity)
		IncreaseCapacity(L);

	array = L->ArrayList;
	if (index == L->Size - 1)
		Insert(L, value);
	else
	{
		MoveTheValuesBackwards(L, index);
		*(array +  index) = value;
	}
	L->Size += 1;
}

void
InsertArray(List L, ElementType* array, int length)
{
	for (int i = 0; i < length; ++i)
		Insert(L, *(array + i));
}

void
Delete(List L)
{
	L->Size -= 1;
}

void
DeleteAt(List L, int index)
{
	if (index > L->Size)
		FatalError("Delete Failed. Illegal index.");
	if (index + 1 == L->Size)
		Delete(L);
	else
	{
		MoveTheValuesForWard(L, index);
		L->Size -= 1;
	}
}

ElementType
Retrieve(List L, int index)
{
	Array array;
	if (index > L->Size)
		FatalError("Illegal index.");
	array = L->ArrayList;
	return array[index];
}

void
MoveTheValuesBackwards(List L, int index)
{
	Array array;
	array = L->ArrayList;
	for (int i = L->Size - 1; i > index - 1; --i)
		*(array + i + 1) = *(array + i);
}

void
MoveTheValuesForWard(List L, int index)
{
	Array array;
	array = L->ArrayList;
	for (int i = index; i < L->Size - 1; ++i)
	{
		*(array + i) = *(array + i + 1);
	}
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
	DeleteArrayList(L->ArrayList, L->Capacity);
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

// TODO
void
DeleteArrayList(Array array, int capacity)
{
	free(array);
}

void
ArrayListTest()
{
	List list;
	list = NewList();
	Insert(list, 1);
	Insert(list, 2);
	TraverseList(list);
	printf("list1 Before Increase Capacity: %d\n", list->Capacity);
	printf("list1 Before Increase Arraylist Pointer: %p\n", list->ArrayList);
	int array[] = {3, 4, 5, 6, 7, 8, 9, 10, 11};
	InsertArray(list, array, 9);
	TraverseList(list);
	
	printf("\n");
	printf("list1 After Increase Capacity: %d\n", list->Capacity);
	printf("list1 After Increase Arraylist Pointer: %p\n", list->ArrayList);

	List list2;
	list2 = NewListWithCapacity(5);
	int array2[] = {1, 2, 3, 4, 5};
	InsertArray(list2, array2, 5);
	TraverseList(list2);
	printf("list2 Before InsertAt Capacity: %d\n", list2->Capacity);
	printf("list2 Before InsertAt Arraylist Pointer: %p\n", list2->ArrayList);

	InsertAt(list2, 2, 6);
	TraverseList(list2);

	printf("list2 After InsertAt Capacity: %d\n", list2->Capacity);
	printf("list2 After InsertAt Arraylist Pointer: %p\n", list2->ArrayList);

	Delete(list2);
	TraverseList(list2);
	DeleteAt(list2, 2);
	TraverseList(list2);

	printf("%d\n", Retrieve(list2, 2));
}