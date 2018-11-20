#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "../errors/myerror.h"

// Definition of Nodes, Of course you can use different data type.
struct Node
{
	int Value;
	Position Next;
};

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
Find(List L, int target)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Value!= target)
		P = P->Next;
	return P;
}

// Delete a node with value equals target, if you got two same value in a linkedlist, you may just delete the first one.
void
Delete(List L, int target)
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
FindPrevious(List L, int target)
{
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->Value != target)
		P = P->Next;

	return P;
}

// Pick a position where you wanna insert a value behind it.
void
Insert(List L, Position P, int value)
{
	Position TmpPointer;
	TmpPointer = (struct Node *)malloc(sizeof(struct Node));
	if (TmpPointer == NULL)
		FatalError("No room!!");
	TmpPointer->Value = value;
	TmpPointer->Next = P->Next;
	P->Next = TmpPointer;
}

// free all nodes, you should keep a pointer point at next node you wanna free.
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
FatalError(char *msg)
{
	printf("fatal error: %s\n", msg);
	exit(1);
}

int
main()
{
	FatalError("No room");
	return 0;
}
