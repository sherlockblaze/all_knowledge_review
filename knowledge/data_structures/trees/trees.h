#ifndef _TREES_H_
#define _TREES_H_

#define ElementType int

typedef TreeNode *PtrToNode;

#endif /*_TREES_H_*/

struct TreeNode
{
	ElementType Value;
	PtrToNode FirstChild;
	PtrToNode NextSibling;
};