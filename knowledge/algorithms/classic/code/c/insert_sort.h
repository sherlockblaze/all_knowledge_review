#ifndef _INSERT_SORT_H_
#define _INSERT_SORT_H_

void insert_sort(int *p, int length);
void insert_sort_test();

#endif /*_INSERT_SORT_H_*/

#include <stdio.h>

void
insert_sort(int *p, int length)
{
	int key = 0;
	// start from the second element
	for (int i = 1; i < length; ++i)
	{
		key = p[i];
		int j = i - 1;
		while (j >= 0 && p[j] > key)
		{
			p[j + 1] = p[j];
			j = j - 1;
		}
		p[j + 1] = key;
	}
}

void
insert_sort_test()
{
	int a[] = {15, 1, 51, 6, 13};
	printf("before sorted!\n");
	for (int i = 0; i < 5; ++i)
		printf("%d\t", a[i]);
	insert_sort(a, 5);
	printf("\nafter sorted\n");
	for (int i = 0; i < 5; ++i)
		printf("%d\t", a[i]);
	printf("\n");
}
