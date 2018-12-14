#ifndef _TWOSUM_H_
#define _TWOSUM_H_

int *twoSum(int* nums, int numsSize, int target);
int *betterOne(int* nums, int numsSize, int target);
/*We'll implement this one when we get hashmap*/
int *bestOne(int* nums, int numsSize, int target);
void twoSumTest(int *nums, int numsSize, int target);

#endif /*_TWOSUM_H_*/

#include <stdio.h>
#include <stdlib.h>

// O(n^2)
int*
twoSum(int* nums, int numsSize, int target)
{
	int i = 0;
	int j;
	int* result = (int*)malloc(sizeof(int) * 2);
	for (; i < numsSize; ++i)
	{
		int remain = target - *(nums + i);
		for (j = i + 1; j < numsSize; ++j)
			if (*(nums + j) == remain)
			{
				result[0] = i;
                result[1] = j;
                break;
			}
	}
	return result;
}

// Waste too much space, if we got [0, 1000, 1, 441, 1], we need almost 4.2M, if we got bigger number, it'll take much more. But the cost of space is O(n)
/*int* 
betterOne(int* nums, int numsSize, int target) {
	int i, max, min;
	max = min = nums[0];
	for (i = 0; i < numsSize; ++i)
	{
		if (nums[i] > max) max = nums[i];
		if (nums[i] < min) min = nums[i];
	}
	int *map = (int*)calloc((max - min + 1), sizeof(int));
	int *reval = (int*)malloc(sizeof(int) * 2);

	for (i = 0; i < numsSize; map[nums[i] - min] = ++i)
	{
		int lookfornum = target - nums[i];
		if (lookfornum < min || lookfornum > max) continue;
		int dis = lookfornum - min;
		printf("mapdis= %d\n", map[dis]);
		if (map[dis])
		{
			reval[0] = i;
			reval[1] = map[dis] - 1;
			break;
		}
	}
	free(map);
	printf("in function: %d, %d\n", reval[0], reval[1]);
	return reval;
}*/

void
twoSumTest(int* nums, int numsSize, int target)
{
	int* resultOne = twoSum(nums, numsSize, target);
	// int* resultTwo = betterOne(nums, numsSize, target);
	printf("twoSum result: %d, %d\n", resultOne[0], resultOne[1]);
	// printf("betterOne result: %d, %d\n", resultTwo[0], resultTwo[1]);
	free(resultOne);
	// free(resultTwo);
}