# Loop Invariants

## Contents

- [What is Loop Invariants](#What-is-Loop-Invariants)
- [Example](#Example)

### What is Loop Invariants

> At the start of each iteration of the ***for*** loop, the subarray A[i..j-1] consists of the elements originally in A[1..j-1], but in sorted order.
> ***We use loop invariants to help us understand why an algorithms is correct.***

We must show three things about a loop invariants.

1. ***Initalization:*** It is true prior to the first iteration of the loop.
2. ***Maintenance:*** If it is true before an iteration of the loop, it remains true before the next iteration.
3. ***Termination:*** When the loop terminates, the invariant gives us a useful property that helps show that the algorithm is correct.

### Example

Now Let's learn more about Invariants by talking about [Insertion-Sort](../algorithms/README.md/#Insertion-Sort) from three things we talk about:

1. ***Initalization:*** Before the first loop, we got the A[1]. Moreover, ***this subarray is sorted, which shows that the loop invariant holds prior to the first iteration of the loop.***
2. ***Maintenance:*** here, we should talk about the second property: showing that each iteration maintains the loop invariant. That's pretty easy. If you got A[1..2], and you must know the subarray consists of the elements originally in A[1...2], and it gets sorted. Moreover, you can know about A[1...3], A[1...4] and so on. So it's true before an iteration of the loop, it remains true before the next iteration. It's Maintenance.
3. ***Termination:*** We already know that the subarray is sorted, so when we finished the loop, we got a subarray has already been sorted. You know even A[0...A.length] is a subarray of A.

***So that, we can know the algorithms is correct by check the loop invariants. It's a bit like mathematical induction. But we stop the "induction" when loop terminates.***