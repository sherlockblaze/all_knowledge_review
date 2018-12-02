#ifndef _LINKEDLIST_WITH_TAIL_POINTER_H_
#define _LINKEDLIST_WITH_TAIL_POINTER_H_
// #define ElementType int


struct Node;

// Definition
typedef struct Node *PtrToNode;
typedef struct HeadNode *PtrToHead;
typedef PtrToHead List;
// typedef PtrToNode List;
typedef PtrToNode Position;

// Operation
List NewList();
int IsEmpty(List L);
ElementType IsLast(Position P);
Position FindFirst(List L, ElementType target);
void Delete(List L);
void DeleteAt(List L, int index);
void DeleteFirstTarget(List L, ElementType target);
void DeleteAllTarget(List L, ElementType target);
Position FindPrevious(List L, ElementType target);
void Insert(List L, ElementType value);
void InsertArray(List L, ElementType *array, int length);
void InsertAt(List L, int index, ElementType value);
void InsertBefore(List L, int index, ElementType value);
void InsertAfter(List L, int index, ElementType value);
void DeleteList(List L);
ElementType Retrieve(List L, int index);


#endif /* _LINKEDLIST_WITH_TAIL_POINTER_H_ */

#include <stdio.h>
#include <stdlib.h>
#include "../errors/myerror.h"

// Definition of Nodes,	you can change the definition of ElementyType for changing the type of value.
struct HeadNode
{
	int Size;
	Position Head;
	Position Tail;
};

struct Node
{
	ElementType Value;
	Position Next;
};

List
NewList()
{
	List list = (struct HeadNode *) malloc(sizeof(struct Node));
	list->Size= 0;
	list->Head= NULL;
	list->Tail= NULL;
	return list;
}

// Check the list whether is empty list or not
int
IsEmpty(List L)
{
	return L->Size == 0;
}

// Check the node with position P whether is the last node or not
int
IsLast(Position P)
{
	return P->Next == NULL;
}

// Find the node with value equals target, of course, if you got two same value in a linkedlist, you just get the position of the first one.
Position
FindFirst(List L, ElementType target)
{
	Position P;
	P = L->Head;
	while (P != NULL && P->Value!= target)
		P = P->Next;
	return P;
}

// Delete the last node of list L
void
Delete(List L)
{
	if (L == NULL || L->Size == 0)
		FatalError("Delete failed. Please try to create a list and insert some nodes into it.");
	Position P, Previous;
	P = L->Head;
	if (L->Size == 1)
	{
		L->Head = NULL;
		L->Tail = NULL;
	}
	else
	{
		while (P->Next != NULL)
		{
			Previous = P;
			P = P->Next;
		}
		Previous->Next = NULL;
		L->Size -= 1;
		L->Tail = Previous;
	}
	free(P);
}

// Delete the node at the index you give
void
DeleteAt(List L, int index)
{
	if (index > L->Size - 1)
		FatalError("Illegal index");
	Position P, NewNext;
	P = L->Head;
	if (index == 0)
	{
		NewNext = P->Next;
		L->Head = NewNext;
		free(P);
	}
	else
	{
		int i = 0;
		while (++i < index)
			P = P->Next;
		NewNext = P->Next->Next;
		free(P->Next);
		P->Next = NewNext;
	}
	L->Size -= 1;
}

// Delete a node with value equals target, if you got two same value in a linkedlist, you may just delete the first one.
void
DeleteFirstTarget(List L, ElementType target)
{
	Position P, TmpPointer;
	P = L->Head;
	if (P != NULL && P->Value == target)
		DeleteAt(L, 0);
	else
	{
		P = FindPrevious(L, target);
		if (!IsLast(P))
		{
			TmpPointer = P->Next;
			if (TmpPointer->Next == NULL)
				L->Tail = P;
			P->Next = TmpPointer->Next;
			free(TmpPointer);
			L->Size -= 1;
		}
	}
}

void
DeleteAllTarget(List L, ElementType target)
{
	Position P, TmpPointer;
	while (1)
	{
		if (L->Head->Value == target)
			DeleteAt(L, 0);
		else
		{
			P = FindPrevious(L, target);
			if (!IsLast(P))
			{
				TmpPointer = P->Next;
				if (TmpPointer->Next == NULL)
					L->Tail = P;
				P->Next = TmpPointer->Next;
				free(TmpPointer);
				L->Size -= 1;
			} 
			else
				break;
		}
	}

}

// Find the node before the node with value equals target, but when you got the value more than one time, you all make a mistake.
Position
FindPrevious(List L, ElementType target)
{
	Position P;
	P = L->Head;
	if (L->Head != NULL)
		while (P->Next != NULL && P->Next->Value != target)
			P = P->Next;

	return P;
}

// Insert a value after all elements
void
Insert(List L, ElementType value)
{
	Position NewNode, LastNode;
	NewNode = (struct Node *) malloc(sizeof (struct Node));
	if (NewNode == NULL)
		FatalError("Insert failed. No enough room!!");
	LastNode = L->Head;
	NewNode->Value = value;
	NewNode->Next = NULL;
	if (LastNode == NULL)
		L->Head = NewNode;
	else
	{
		while(LastNode->Next != NULL)
			LastNode = LastNode->Next;
		LastNode->Next = NewNode;
	}
	L->Size += 1;
	L->Tail = NewNode;
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
	if (index > L->Size || index < 0)
		FatalError("Illegal index"); 
	if (index == L->Size)
		Insert(L, value);
	else {
		PtrToNode NewNode = (struct Node *)malloc(sizeof(struct Node));
		if (NewNode == NULL)
			FatalError("No Enough room!");
		NewNode->Value = value;
		Position TmpPointer;
		TmpPointer = L->Head;
		if (index == 0)
		{
			NewNode->Next = L->Head;
			L->Head = NewNode;
		}
		else
		{
			int i = 0;
			while (++i < index)
			{
				TmpPointer = TmpPointer->Next;
			}
			NewNode->Next = TmpPointer->Next;
			TmpPointer->Next = NewNode;
		}
		L->Size += 1;
	}
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
// TODO
void
DeleteList(List L)
{
	Position P, TmpPointer;

	P = L->Head;
	free(L);
	while (P != NULL)
	{
		TmpPointer = P->Next;
		free(P);
		P = TmpPointer;
	}
	printf("Delete Successed\n");
}

ElementType
Retrieve(List L, int index)
{
	Position TmpPointer;
	TmpPointer = L->Head;
	if (index < L->Size)
	{
		int i = 0;
		while (i++ < index)
			TmpPointer = TmpPointer->Next;
		return TmpPointer->Value;
	}
	FatalError("Sorry! No Enough Nodes");
}