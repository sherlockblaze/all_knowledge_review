#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "./linkedlist_with_tail_pointer.h"

typedef List Queue;
List NewQueue();
void Enqueue(Queue Queue, ElementType Value);
ElementType Dequeue(Queue Queue);

#endif /*_QUEUE_H_*/

#include <stdio.h>

Queue
NewQueue()
{
	return NewList();
}

void
Enqueue(Queue Queue, ElementType Value)
{
	Insert(Queue, Value);
}

ElementType
Dequeue(Queue Queue)
{
	ElementType Value;
	Value = Queue->Head->Value;
	DeleteAt(Queue, 0);
	return Value;
}