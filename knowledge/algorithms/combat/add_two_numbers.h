#include "../../data_structures/lists/linkedlist.h"

#ifndef _ADD_TWO_NUMBERS_H_
#define _ADD_TWO_NUMBERS_H_

#define ElementType int

List addTwoNumbers(List l1, List l2);
void TraverseList(List L);
void test();

#endif /*_ADD_TWO_NUMBERS_H_*/


List
addTwoNumbers(List l1, List l2)
{
	int overflow = 0;
	List result = NewList();
	Position l1_node, l2_node;

	if (l1 != NULL)
		l1_node = l1->Next;
	if (l2 != NULL)
		l2_node = l2->Next;

	while (1)
	{
		if (l1_node != NULL)
		{
			overflow += l1_node->Value;
			l1_node = l1_node->Next;
		}
		if (l2_node != NULL)
		{
			overflow += l2_node->Value;
			l2_node = l2_node->Next;
		}
		InsertAt(result, 0, overflow % 10);
		overflow /= 10;

		if (l1_node == NULL && l2_node == NULL && overflow == 0)
			break;
	}
	return result;
}

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

void
test()
{
	List l1 = NewList();
	List l2 = NewList();
	int num1[] = {5};
	int num2[] = {5};
	InsertArray(l1, num1, 1);
	InsertArray(l2, num2, 1);
	TraverseList(l1);
	TraverseList(l2);
	List result = addTwoNumbers(l1, l2);
	TraverseList(result);
	DeleteList(l1);
	DeleteList(l2);
	DeleteList(result);
}