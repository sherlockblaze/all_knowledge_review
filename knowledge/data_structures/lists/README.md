## Contents
- [LinkedList](#LinkedList)
- [Doubly LinkedList](#Doubly-LinkedList)
- [ArrayList](#ArrayList)

### LinkedList

- [Operations](#linkedlist_operations)
- [Conclusion](#linkedlist_conclusion)

Here is the linked list. It looks like this.

![LinkedList](../../pictures/data_structures/linkedlist/linkedlist.png)

> In order to avoid the linear cost of insertion and deletion, we need to ensure that the list is not stored contiguously. By using this kind of list, we can make the cost of insertion and deletion be O(1).
The linked list consists of a series of structures, which are not necessarily adjacent in memory.
Each node contains the element and a pointer points to the next node, we call it Next pointer, And the last node's Next pointer points to NULL. And ANSI C specifies that NULL is zero.

In my version, I put a head node to save the length of the linked list.

![With Head Node](../../pictures/data_structures/linkedlist/linkedlist_with_head_node.png)

Now we can see the operations of LinkedList.

<h4 id="linkedlist_operations">Operations</h4>

- [Insert](#linkedlist_insert)
- [Delete](#linkedlist_delete)

<h5 id="linkedlist_insert">Insert</h5>

![Insert Step1](../../pictures/data_structures/linkedlist/insert_operation_step1.png)

It's the first step of the insert operation.

As we can see, we got Node A, B, C, and the C is the newest node we wanna insert into this list. First we make the Next pointer of C equals Next pointer of A, then the C node's Next Pointer points to node B.

second step, we let the A's Next pointer points to our new node C.

![Insert Step2](../../pictures/data_structures/linkedlist/insert_operation_step2.png)

Finally, we finished it.

***Insert Successed!!***

![Insert Successed](../../pictures/data_structures/linkedlist/insert_success.png)

<h5 id="linkedlist_delete">Delete</h5>

We'll show two steps of delete operation.

First step, we let the node A's Next pointer equals the Next pointer of node C.

![Delete Step1](../../pictures/data_structures/linkedlist/delete_operation_step1.png)

Second step, because we just get one Next pointer for each node, so, it just make no pointer points to node C.

![Delete Step2](../../pictures/data_structures/linkedlist/delete_operation_step2.png)

**So delete Successed!!**

![Delete Successed](../../pictures/data_structures/linkedlist/delete_success.png)

<h5 id="linkedlist_conclusion">Conclusion</h5>

We know that if you just calculate the cost of insertion or deletion, you'll find T(n) = O(1).
But you know if we wanna insert or delete a value with speicify index, it'll cost O(n) in whole operation. But the cost of insertion or deletion still is O(1). Here, we just talk aboult the cost of insertion or deleteion.

### Doubly LinkedList

- [Operations](#doublylinkedlist_operations)
- [Conclusion](#doublylinkedlist_conclusion)

Sometimes it's convenient to traverse lists backwards. We just add an extra field to the data structure, containing a pointer to the previous node.

Here is what Doubly LinkedList looks like.

![Doubly LinkedList](../../pictures/data_structures/doublylinkedlist/doublylinkedlist.png)

In my version, there's still has a head node of the list, and it's value equals the total number of valid nodes.

![Doubly LinkedList With Head Node](../../pictures/data_structures/doublylinkedlist/doublylinkedlist_with_head.png)

Now we can see the basic operations of doubly linkedlist.

<h4 id="doublylinkedlist_operations">Operations</h4>

- [Insert](#doublylinkedlist_insert)
- [Delete](#doublylinkedlist_delete)

<h5 id="doublylinkedlist_insert">Insert</h5>

![Insert Step1](../../pictures/data_structures/doublylinkedlist/insert_step1.png)

First Step, we get a new node called NewNode, and get it ready for insertion. Then we let the Next Pointer of NewNode equals the Next pointer of previous node.

![Insert Step2](../../pictures/data_structures/doublylinkedlist/insert_step2.png)

Then we need to let the Previous pointer of the node that the Next pointer of previous node points to points to the NewNode.

![Insert Step3](../../pictures/data_structures/doublylinkedlist/insert_step3.png)

Let the Next pointer of Previous node points to NewNode

![Insert Step4](../../pictures/data_structures/doublylinkedlist/insert_step4.png)

Now we can let the Previous pointer of NewNode points to the Previous node.

**And then we finished the insertion. Insert at the end of the list is similar to this.**

![Insert Successed](../../pictures/data_structures/doublylinkedlist/insert_successed.png)

<h5 id="doublylinkedlist_delete">Delete</h5>

First, we call the node we want to delete TargetNode.

![Delete Step1](../../pictures/data_structures/doublylinkedlist/delete_step1.png)

As the picture shows, we should let the previous pointer of the next node of the TargetNode points to the previous node of the TargetNode.

![Delete Step2](../../pictures/data_structures/doublylinkedlist/delete_step2.png)

Then we let the Next pointer of previous node points to the next node of the TargetNode.

**Finished!! Just don't forget to free the space of TargetNode.**

![Delete Successed](../../pictures/data_structures/doublylinkedlist/delete_successed.png)

<h5 id="doublylinkedlist_conclusion">Conclusion</h5>

The cost of insertion or deletion still O(1).
It's just as same as [linkedlist](#LinkedList) -- The standard implementation.

### LinkedList

- [Operations](#arraylist_operations)
- [Conclusion](#arraylist_conclusion)

<h4 id="arraylist_operations">Operations</h4>

- [Insert](#arraylist_insert)
- [Delete](#arraylist_delete)

<h5 id="arralylist_insert">Insert</h5>

![Insert Step1](../../pictures/data_structures/arraylist/insert_step1.png)
![Insert Step2](../../pictures/data_structures/arraylist/insert_step2.png)
![Insert Successed](../../pictures/data_structures/arraylist/insert_successed.png)

<h5 id="arralylist_delete">Delete</h5>

![Delete Step1](../../pictures/data_structures/arraylist/delete_step1.png)
![Delete Step2](../../pictures/data_structures/arraylist/delete_step2.png)
![Delete Successed](../../pictures/data_structures/arraylist/delete_successed.png)

<h5 id="arralylist_conclusion">Conclusion</h5>

![Insert Without Enough Room Step1](../../pictures/data_structures/arraylist/insert_without_enough_room_step1.png)
![Insert Without Enough Room Step2](../../pictures/data_structures/arraylist/insert_without_enough_room_step2.png)
![Insert Without Enough Room Step3](../../pictures/data_structures/arraylist/insert_without_enough_room_step3.png)
![Insert Without Enough Room Success](../../pictures/data_structures/arraylist/insert_without_enough_room_Success.png)