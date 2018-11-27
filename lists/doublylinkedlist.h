#ifndef _DOUBLYLINKEDLIST_H_
#define _DOUBLYLINKEDLIST_H_
#define ElementType int

struct Node;

// Definition
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

// Operation
List NewList();
int IsEmpty(List L);
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
void Traverse(List L);
void DoublyLinkedListTest();

#endif /*_DOUBLYLINKEDLIST_H_*/

#include <stdio.h>
#include <stdlib.h>
#include "../errors/myerror.h"

// Definition of Nodes,	you can change the definition of ElementType for changing the type of value.
struct Node
{
	Position Previous;
	ElementType Value;
	Position Next;
};

List
NewList()
{
	List list = (struct Node *) malloc(sizeof(struct Node));
	list->Value = 0;
	list->Next = NULL;
	list->Previous = NULL;
	return list;
}

void
Insert(List L, ElementType value)
{
	PtrToNode NewNode = (struct Node *)malloc(sizeof(struct Node));
	if (NewNode == NULL)
		FatalError("No Enough Room");
	Position TmpPointer = L;
	while (TmpPointer -> Next != NULL)
		TmpPointer = TmpPointer->Next;
	TmpPointer->Next = NewNode;
	NewNode->Value = value;
	NewNode->Next = NULL;
	NewNode->Previous = TmpPointer;
	L->Value += 1;
}

void
InsertArray(List L, ElementType *array, int length)
{
	for (int i = 0; i < length; ++i)
		Insert(L, *(array + i));
}

void
InsertAt(List L, int index, ElementType value)
{
	if (index > L->Value || index < 0)
		FatalError("Wrong Place");
	if (index == L->Value)
		Insert(L, value);
	PtrToNode NewNode = (struct Node *)malloc(sizeof(struct Node));
	if (NewNode == NULL)
		FatalError("No Enough Room");
	Position TmpPointer = L->Next;
	int i = 1;
	while (i < index)
	{
		TmpPointer = TmpPointer->Next;
		++i;
	}
	NewNode->Value = value;
	NewNode->Next = TmpPointer->Next;
	TmpPointer->Next = NewNode;
	NewNode->Previous = TmpPointer;
	L->Value += 1;
}

void
InsertBefore(List L, int index, ElementType value)
{
	InsertAt(L, index - 1, value);
}

void
InsertAfter(List L, int index, ElementType value)
{
	InsertAt(L, index + 1, value);
}

void
Traverse(List L)
{
	if (L == NULL)
		FatalError("No such Doubly LinkedList");
	printf("There're %d elements:\n", L->Value);
	Position TmpPointer = L->Next;
	while (TmpPointer != NULL)
	{
		printf("%d\t", TmpPointer->Value);
		TmpPointer = TmpPointer->Next;
	}
	printf("\n");
}

int
IsEmpty(List L)
{

}

ElementType
IsLast(Position P)
{

}

Position
Find(List L, ElementType target)
{

}

void
DeleteList(List L)
{
	Position P, TmpPointer;
	P = L->Next;

	free(L);
	while (P != NULL)
	{
		TmpPointer = P->Next;
		free(P);
		P = TmpPointer;
	}
}

void
DoublyLinkedListTest()
{
	List list = NewList();
	Insert(list, 2);
	Traverse(list);
	Insert(list, 3);
	Traverse(list);
	InsertAt(list, 1, 4);
	Traverse(list);
	InsertBefore(list, 1, 5);
	Traverse(list);
	InsertAfter(list, 1, 6);
	Traverse(list);
	int array[] = {7, 8, 9, 10, 11, 12};
	InsertArray(list, array, 6);
	Traverse(list);
	DeleteList(list);
	Traverse(list);
}
