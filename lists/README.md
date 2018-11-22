[TOC]

## List README

### LinkedList

Here is the linked list. It looks like this.

![Linkedlist](https://github.com/sherlockblaze/data_structures_review/blob/master/picture/linkedlist.png)

> In order to avoid the linear cost of insertion and deletion, we need to ensure that the list is not stored contiguously. By using this kind of list, we can make the cost of insertion and deletion be O(1).
The linked list consists of a series of structures, which are not necessarily adjacent in memory.
Each node contains the element and a pointer points to the next node, we call it Next pointer, And the last node's Next pointer points to NULL. And ANSI C specifies that NULL is zero.

In my version, I put a head node to save the length of the linked list.

![With Head Node](https://github.com/sherlockblaze/data_structures_review/blob/master/picture/linkedlist_with_head_node.png)

Now we can see the operations of LinkedList.

#### Operation

##### Insert

![Insert](https://github.com/sherlockblaze/data_structures_review/blob/master/picture/insert_operation.png)

It's the process of the insert operation.

As we can see, we got Node A, B, C, and the C is the newest node we wanna insert into this list. First we make the Next pointer of C equals Next pointer of A, then the C node's Next Pointer points to node B, then we let the A's Next pointer points to our new node C.