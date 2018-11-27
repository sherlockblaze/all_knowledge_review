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
int IsEmpty(List L);
ElementType IsLast(Position P);
Position Find(List L, ElementType target);
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

// Delete the last node of list L
void
Delete(List L)
{
	if (L == NULL || L->Value == 0)
		printf("Delete failed. Please try to create a list and insert some nodes into it.");
	Position P, TmpPointer;
	P = L->Next;
	while (P->Next != NULL)
	{
		TmpPointer = P;
		P = P->Next;
	}
	TmpPointer->Next = NULL;
	L->Value -= 1;
	free(P);
}

// Delete the node at the index you give
void
DeleteAt(List L, int index)
{
	Position P;
	P = L;
	int i = 0;
	while (i++ < index)
	{
		P = P->Next;
	}
	Position NewNext = P->Next->Next;
	free(P->Next);
	P->Next = NewNext;
	L->Value -= 1;
}

// Delete a node with value equals target, if you got two same value in a linkedlist, you may just delete the first one.
void
DeleteFirstTarget(List L, ElementType target)
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

void
DeleteAllTarget(List L, ElementType target)
{
	Position P, TmpPointer;
	while (1)
	{
		P = FindPrevious(L, target);
		if (!IsLast(P))
		{
			TmpPointer = P->Next;
			P->Next = TmpPointer->Next;
			free(TmpPointer);
			L->Value -= 1;
		} 
		else
			break;
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
		FatalError("Insert failed. No enough room!!");
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
	if (index > L->Value || index < 0)
		FatalError("Sorry! Wrong index!!"); 
	if (index == L->Value)
		Insert(L, value);
	PtrToNode NewNode = (struct Node *)malloc(sizeof(struct Node));
	if (NewNode == NULL)
		FatalError("No Enough room!");
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
// TODO
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
	printf("Delete Successed\n");
}

// Traverse the list
void
TraverseList(List L)
{
	if (L == NULL)
		FatalError("No such linkedlist");
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
	List list;
	// list = NULL;
	// TraverseList(list);
	list = NewList();
	TraverseList(list);
	Insert(list, 1);
	TraverseList(list);
	Insert(list, 25);
	TraverseList(list);
	int values1[5] = {1, 2, 3, 4, 5};
	InsertArray(list,values1, 5);
	TraverseList(list);
	InsertAt(list, 3, 99);
	TraverseList(list);
	InsertBefore(list, 3, 127);
	TraverseList(list);
	InsertAfter(list, 3, 925);
	TraverseList(list);
	// InsertAfter(list, 12, 999);
	Delete(list);
	TraverseList(list);
	DeleteAt(list, 1);
	TraverseList(list);
	DeleteAt(list, 3);
	TraverseList(list);
	Retrieve(list, 3);
	int values2[5] = {7 ,7, 7, 7, 7};
	InsertArray(list, values2, 5);
	TraverseList(list);
	DeleteFirstTarget(list, 7);
	TraverseList(list);
	DeleteAllTarget(list, 7);
	TraverseList(list);
	DeleteList(list);
	TraverseList(list);
}