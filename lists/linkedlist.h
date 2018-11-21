#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#define ElementType int


struct Node;
// Definition
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

// Operation
List NewList();
List MakeEmpty(List L);
ElementType IsEmpty(List L);
ElementType IsLast(Position P);
Position Find(List L, ElementType target);
void Delete(List L, ElementType target);
Position FindPrevious(List L, ElementType target);
int Insert(List L, ElementType value);
int InsertArray(List L, ElementType *array, int length);
int InsertAt(List L, int index, ElementType value);
int InsertBefore(List L, int index, ElementType value);
int InsertAfter(List L, int index, ElementType value);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
void TraverseList(List L);
void ListTest();

#endif /* _Linkedlist_H */

#include <stdio.h>
#include "../errors/myerror.h"

// Definition of Nodes, Of course you can use different data type.
struct Node
{
	ElementType Value;
	Position Next;
};

List
NewList()
{
	List list = (struct Node *)malloc(sizeof(struct Node));
	list->Value = 0;
	list->Next = NULL;
	return list;
}

// Check the list whether is empty list or not
int
IsEmpty(List L)
{
	return L->Next == NULL;
}

// Check the node with position P whether is the last node or not
int
IsLast(Position P)
{
	return P->Next == NULL;
}

// Find the node with value equals target, of course, if you got two same value in a linkedlist, you just get the position of the first one.
Position
Find(List L, ElementType target)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Value!= target)
		P = P->Next;
	return P;
}

// Delete a node with value equals target, if you got two same value in a linkedlist, you may just delete the first one.
void
Delete(List L, ElementType target)
{
	Position P, TmpPointer;
	P = FindPrevious(L, target);
	if (!IsLast(P))
	{
		TmpPointer = P->Next;
		P->Next = TmpPointer->Next;
		free(TmpPointer);
		L->Value -= 1;
	}
}

// Find the node before the node with value equals target, but when you got the value more than one time, you all make a mistake.
Position
FindPrevious(List L, ElementType target)
{
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->Value != target)
		P = P->Next;

	return P;
}

// Insert a value after all elements
int
Insert(List L, ElementType value)
{
	Position TmpPointer, LastNode;
	TmpPointer = (struct Node *) malloc(sizeof (struct Node));
	if (TmpPointer == NULL)
	{
		FatalError("No room!!");
		return 0;
	}
	LastNode = L;
	while(LastNode->Next != NULL)
		LastNode = LastNode->Next;
	TmpPointer->Value = value;
	TmpPointer->Next = NULL;
	LastNode->Next = TmpPointer;
	L->Value += 1;
	return 1;
}

// Insert a Array after all elements
int
InsertArray(List L, ElementType *array, int length)
{
	for(int i = 0; i < length; ++i)
		if (!Insert(L, *(array+i)))
		{
			FatalError("No Enough room!!");
			printf("Inserted %d values", i + 1);
			return 0;
		}
	return 1;
}

// Insert a Value at the index you give
int
InsertAt(List L, int index, ElementType value)
{
	if (index > L->Value)
	{
		FatalError("Sorry!"); 
		printf("There're just %d elements.", L->Value);
		return 0;
	}
	if (index == L->Value)
	{
		Insert(L, value);
	}
	PtrToNode NewNode = (struct Node *)malloc(sizeof(struct Node));
	if (NewNode == NULL)
	{
		FatalError("No room!");
		return 0;
	}
	NewNode->Value = value;
	Position TmpPointer;
	TmpPointer = L->Next;
	int i = 1;
	while (i < index)
	{
		TmpPointer = TmpPointer->Next;
		++i;
	}
	NewNode->Next = TmpPointer->Next;
	TmpPointer->Next = NewNode;
	L->Value += 1;
	return 1;
}

int
InsertBefore(List L, int index, ElementType value)
{
	InsertAt(L, index - 1, value);
}

int
InsertAfter(List L, int index, ElementType value)
{
	InsertAt(L, index + 1, value);
}

// free all nodes, you should keep a pointer point ElementType at next node you wanna free.
void
DeleteList(List L)
{
	Position P, TmpPointer;

	P = L->Next;
	L->Next = NULL;
	while (P != NULL)
	{
		TmpPointer = P->Next;
		free(P);
		P = TmpPointer;
	}
}

void
TraverseList(List L)
{
	printf("There're %d elements:\n", L->Value);
	Position TmpPointer = L->Next;
	while(TmpPointer != NULL)
	{
		printf("%d\t", TmpPointer->Value);
		TmpPointer = TmpPointer->Next;
	}
	printf("\n");
}

void
ListTest()
{
	List list = NewList();
	printf("Is Empty %d:\n", IsEmpty(list));
	TraverseList(list);
	printf("Insert Value 1: %d\n", Insert(list, 1));
	TraverseList(list);
	printf("Insert Value 25: %d\n", Insert(list, 25));
	TraverseList(list);
	int values[5] = {1, 2, 3, 4, 5};
	printf("Insert Values: %d\n", InsertArray(list, values, 5));
	TraverseList(list);
	printf("Insert At index 3: %d\n", InsertAt(list, 3, 99));
	TraverseList(list);
	printf("Insert Before index 3: %d\n", InsertBefore(list, 3, 127));
	TraverseList(list);
	printf("Insert After index 3: %d\n", InsertAfter(list, 3, 925));
	TraverseList(list);
	printf("Insert After index 12: %d\n", InsertAfter(list, 12, 999));
	TraverseList(list);
}