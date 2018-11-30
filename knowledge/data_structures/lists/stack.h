#ifndef _STACK_H_
#define _STACK_H_

// #define ElementType int

#include "./linkedlist.h"

typedef List Stack;
List NewStack();
void Push(Stack Stack, ElementType Value);
ElementType Pop(Stack Stack);

#endif /*_STACK_H_*/

#include <stdio.h>

Stack
NewStack()
{
	return NewList();
}

void
Push(Stack Stack, ElementType Value)
{
	InsertAt(Stack, 0, Value);
}

ElementType
Pop(Stack Stack)
{
	ElementType Value;
	Value = Stack->Next->Value;
	DeleteAt(Stack, 0);
	return Value;
} 