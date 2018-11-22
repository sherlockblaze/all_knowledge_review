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
void Insert(List L, ElementType value);
void InsertArray(List L, ElementType *array, int length);
void InsertAt(List L, int index, ElementType value);
void InsertBefore(List L, int index, ElementType value);
void InsertAfter(List L, int index, ElementType value);
void DeleteList(List L);
ElementType Retrieve(List L, int index);
void TraverseList(List L);
void ListTest();

#endif /* _Linkedlist_H */

#include <stdio.h>
#include "../errors/myerror.h"

// Definition of Nodes,	you can change the definition of ElementyType for changing the type of value.
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
void
Insert(List L, ElementType value)
{
	Position TmpPointer, LastNode;
	TmpPointer = (struct Node *) malloc(sizeof (struct Node));
	if (TmpPointer == NULL)
	{
		FatalError("Insert failed. No enough room!!");
	}
	LastNode = L;
	while(LastNode->Next != NULL)
		LastNode = LastNode->Next;
	TmpPointer->Value = value;
	TmpPointer->Next = NULL;
	LastNode->Next = TmpPointer;
	L->Value += 1;
}

// Insert a Array after all elements
void
InsertArray(List L, ElementType *array, int length)
{
	for(int i = 0; i < length; ++i)
		Insert(L, *(array+i));
}

// Insert a Value at the index you give
void
InsertAt(List L, int index, ElementType value)
{
	if (index > L->Value)
	{
		FatalError("Sorry! Wrong index!!"); 
	}
	if (index == L->Value)
	{
		Insert(L, value);
	}
	PtrToNode NewNode = (struct Node *)malloc(sizeof(struct Node));
	if (NewNode == NULL)
	{
		FatalError("No Enough room!");
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
}

// Insert a value before the index you give
void
InsertBefore(List L, int index, ElementType value)
{
	InsertAt(L, index - 1, value);
}

// Insert a value after the index you give
void
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

// Traverse the list
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

ElementType
Retrieve(List L, int index)
{
	Position TmpPointer;
	TmpPointer = L->Next;
	if (index < L->Value)
	{
		int i = 1;
		while (i < index)
		{
			TmpPointer = TmpPointer->Next;
			++i;
		}
		return TmpPointer->Value;
	}
	FatalError("Sorry! No Enough Nodes");
}

void
ListTest()
{
	List list = NewList();
	TraverseList(list);
	Insert(list, 1);
	TraverseList(list);
	Insert(list, 25);
	TraverseList(list);
	int values[5] = {1, 2, 3, 4, 5};
	InsertArray(list,values, 5);
	TraverseList(list);
	InsertAt(list, 3, 99);
	TraverseList(list);
	InsertBefore(list, 3, 127);
	TraverseList(list);
	InsertAfter(list, 3, 925);
	TraverseList(list);
	// InsertAfter(list, 12, 999);
	TraverseList(list);
	Retrieve(list, 9);
}