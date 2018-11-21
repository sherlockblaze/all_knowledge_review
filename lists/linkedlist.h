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
ElementType IsEmpty(List LA);
ElementType IsLast(Position P);
Position Find(List L, ElementType target);
void Delete(List L, ElementType target);
Position FindPrevious(List L, ElementType target);
int Insert(List L, ElementType value);
int InsertArray(List L, ElementType *Array, int length);
int InsertAt(List L, int index, ElementType value);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
void TraverseList(List L);

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
	return 1;
}

int
InsertArray(List L, ElementType *Array, int length)
{
	for(int i = 0; i < length; ++i)
		if (!Insert(L, *(Array+i)))
		{
			FatalError("No Enough room!!");
			printf("Inserted %d values", length + 1);
			return 0;
		}
	return 1;
}

// Pick a position where you wanna insert a value behind it.
int
InsertAt(List L, int index, ElementType value)
{
	/*Position TmpPointer;
	TmpPointer = (struct Node *)malloc(sizeof(struct Node));
	if (TmpPointer == NULL)
	{
		FatalError("No room!!");
		return 0;
	}
	TmpPointer->Value = value;
	TmpPointer->Next = P->Next;
	P->Next = TmpPointer;
	return 1;*/
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
	Position TmpPointer = L->Next;
	while(TmpPointer != NULL)
	{
		printf("%d\t", TmpPointer->Value);
		TmpPointer = TmpPointer->Next;
	}
	printf("\n");
}