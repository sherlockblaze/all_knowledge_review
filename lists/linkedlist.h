#ifndef _Linkedlist_H

struct Node;
// Definition
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

// Operation
List MakeEmpty(List L);
int IsEmpty(List LA);
int IsLast(Position P);
Position Find(List L, int target);
void Delete(List L, int target);
Position FindPrevious(List L, int target);
void Insert(List L, Position P, int value);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
int Retrieve(Position P);

#endif /* _Linkedlist_H */