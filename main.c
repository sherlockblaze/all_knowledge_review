#include <stdio.h>
#include <stdlib.h>
#include "./lists/linkedlist.h"
#include "./algorithms/basic/insert_sort.h"
#include "./algorithms/leetcode/twosum.h"

int
main()
{
	// ListTest();
	// insert_sort_test();
	int nums[] = {2, 7, 11, 15};
	twoSumTest(nums, 4, 9);
	int *result = twoSum(nums, 4, 9);
	for (int i = 0; i < 2; ++i)
	{
		printf("%d\t", *(result+i));
	}
	free(result);
	int *resultTwo = betterOne(nums, 4, 9);
	for (int i = 0; i < 2; ++i)
	{
		printf("%d\t", *(resultTwo+i));
	}
	

	return 0;
}
