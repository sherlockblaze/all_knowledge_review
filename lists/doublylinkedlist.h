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
void TraverseList(List L);
void ListTest();

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
	NewNode->Next = NULL:
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
	PtrToNode NewNode = (Struct Node *)malloc(sizeof(struct Node));
	if (NewNode == NULL)
		FatalError("No Enough Room");
	Position TmpPointer = L;
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

List
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
