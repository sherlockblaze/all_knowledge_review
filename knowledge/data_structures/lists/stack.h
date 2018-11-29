#ifndef _STACK_H_
#define _STACK_H_

#define ElementType int

#include "./linkedlist.h"

typedef List Stack;
List NewStack();
void Push(Stack Stack, ElementType Value);
ElementType Pop(Stack Stack);
void CheckValues(Stack Stack);
void StackTest();

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

void
CheckValues(Stack Stack)
{
	TraverseList(Stack);
}

void
StackTest()
{
	Stack stack;
	stack = NewStack();
	Push(stack, 1);
	Push(stack, 2);
	CheckValues(stack);
	printf("pop: %d\n", Pop(stack));
	CheckValues(stack);
}
