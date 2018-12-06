## AVL Trees

- [Definition](#Definition)
- [Operations](#Operations)

### Definition

AVL Tree -- **Adelson-Velskii and Landis**.

It's a binary tree with a **balance condition**.

> And we get **the balance condition must be easy to maintain, and it ensures that the depth of the tree is O(logN).**

As we know, and AVL tree is identical to a binary search tree, except that for **every node in the tree, the height of the left and right subtrees can differ by at most 1.** (The hight of an empty tree is defined to be -1.)

> Do you guys remember what is depth of a node??

> We review quickly here. **A depth of a node is length of the only way from root to this node.** And if you almost forget the basic concepts of trees. Go [there](./Trees.md#Basic-Concept-Of-Tree) for more.

![](../../pic/trees/what_is_a_avl_tree.png)

We get two binary search tree above.

But only the left one is a AVL tree. And we all know why now. If you don't know why, read one more above.

### Operations

- [Insertion](#Insertion)
    - [Rotation](#Rotation)
        - [Single Rotation](#Single-Rotation)
        - [Double Rotation](#Double-Rotation)
- [Deletion](#Deletion)

It's same with binary search tree when you wanna do some search in a AVL tree. Because we know, AVL trees all are binary search tree. We talk more about **[Insertion](#Insertion)** and **[Deletion](#Deletion)**.

#### Insertion

Because of the balance condition, when we do an insertion, we need to update all the balancing information for the nodes on the path back to the root, why we need to do this? **Because that insertion is potentially violate the AVL tree property.**
For example, if we insert 10 maybe bigger into the left tree above would destroy the balance condition at the node with value 8. Because if we do this, **the node with value 8 in the tree, the height of the left and right subtrees of it differ bigger than 1.**

![Not AVL anymore](../../pic/trees/not_avl_anymore.png)

Not AVL Tree any more.

**We should keep the average depth of tree is O(logN).** It turns out that this can always be done with a simple modification to the tree, known as a ***[rotation](#Rotation)***.

##### Rotation

If we wanna do a rotation, we should find the node must be rebalanced, let's call it **Target**.

> ***Target means the node must be rebalanced now.***

We can know that the Target **must on the path from the insertion point to the root**, ***because only those nodes have altered their subtrees.***
As we follow the path up to the root and update the balancing information, we may find a node whose new balance violates the AVL condition.

When we find the ***Target***, we can do some operations on it.

We get four situations when the tree's balance condition is broken.

1. **An insertion into the left subtree of the left child of Target.**
2. **An insertion into the right subtree of the left child of Target.**
3. **An insertion into the left subtree of the right child of Target.**
4. **An insertion into the right subtree of the right child of Target.**

> Because any node has at most two children, and a height imbalance requires that the Target's two subtrees' height differ by two.

Let's see them before.

***Avl Tree***

![Avl Tree](../../pic/trees/example_avl_tree1.png)

***First situation***

> The Target is 8.

![Situation One](../../pic/trees/avl_situation1.png)

***Second situation***

> The Target is 8.

![Situation Two](../../pic/trees/avl_situation2.png)

***Avl Tree***

> The target is 6

![AVL Tree](../../pic/trees/example_avl_tree2.png)

***Third Situation***

> The target is 6.

![Situation Three](../../pic/trees/avl_situation3.png)

***Fourth Situation***

![Situation Four](../../pic/trees/avl_situation4.png)

> Case 1 and 4 are mirror image symmetries with respect to Target, as are case 2 and 3.
But it's different from a programming perspective.

###### Single Rotation

###### Double Rotation

