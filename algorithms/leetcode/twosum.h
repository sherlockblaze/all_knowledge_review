/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,

return [0, 1].*/

#ifndef _TWOSUM_H_
#define _TWOSUM_H_

int *twoSum(int* nums, int numsSize, int target);
int *betterOne(int* nums, int numsSize, int target);
int *bestOne(int* nums, int numsSize, int target);
void twoSumTest(int *nums, int numsSize, int target);

#endif /*_TWOSUM_H_*/

#include <stdio.h>
#include <stdlib.h>

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

int* 
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
}

void
twoSumTest(int* nums, int numsSize, int target)
{
	int* resultOne = twoSum(nums, numsSize, target);
	int* resultTwo = betterOne(nums, numsSize, target);
	printf("twoSum result: %d, %d\n", resultOne[0], resultOne[1]);
	printf("betterOne result: %d, %d\n", resultTwo[0], resultTwo[1]);
	free(resultOne);
	free(resultTwo);
}