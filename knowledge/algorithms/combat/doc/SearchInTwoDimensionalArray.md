### Search In Two Dimensional Array

- [Question](#Question)
- [Thought](#Thought)
- [Code](#Code)

##### Question

In a two-dimensional array, each row is arranged in increasing order from left to right, and each column is arranged in increasing order from top to bottom. Please write a function, enter a two-dimensional array of this type and an integer to determine if the array contains the integer.

For example, there're a two-dimensional array.


| 1 | 2 | 8 | 9 |
| --- | --- | --- | --- |
| **2** | **4** | **9** | **12** |
| **4** | **7** | **10** | **13** |
| **6** | **8** | **11** | **15** |

If we search for number 7, return true, because there's a number equals 7 in this two-dimensional array. But if we search for number 5, it's return false.

##### Thought

Let's continue talk about this problem by using the example above. Ok, because we want to know a number whether in this array or not, we should compare with the value in this array, if we get a number in the array equals to the number, it's true, or not.

Then if we start with the first value of the array, means start with arr[0][0], if the number is bigger than the arr[0][0], we'll know the if the number is in this array, it must at the **right** of arr[0][0], or in the **below** of it. But which direction we should choose to continue to compare. Maybe we can choose both, but it will be complicate. It costs too much.

Fortunately, we get a better way. we can start with element in the upper right corner. That's be better. Let's see more about it.

If we start with the element in the upper right corner, we can know, for example, number 7, a two-dimensional array above, if we start with number 9, we'll know, number 7 is smaller than number 9, and the numbers in below of number 9 all bigger than number 9, so if number is in this array, it can't be under the number 9, so we can exclude the column where the number 9 is located. If we get a number bigger than number 9, what we should do, just exclude the row where the number 9 is located, pretty easy. Let's move on, because we exclude the column where the number 9 is located, the element in the upper right corner now is number 8, we can exclude this column in a same way, then the number in the upper right corner turn to 2, and so on. we finally can get a number equals to number 7, the return value of the function is true.

##### Code

In the code, I simulated a two-dimensional array with a one-dimensional array, see specific calculations from the code: [C Version](../code/c/search_in_two_dimensional_array.h).