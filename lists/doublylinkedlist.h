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

#endif /*_DOUBLYLINKEDLIST_H_*/

#include <stdio.h>
#include <stdlib.h>
#include "../errors/myerror.h"

// Definition of Nodes,	you can change the definition of ElementyType for changing the type of value.
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