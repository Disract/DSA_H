#ifndef SINGLY_H
#define SINGLY_H
typedef struct LNode LNode;
LNode* LcreateNode(int data);
void LinsertEnd(LNode *head, int data);
LNode* LinsertStart(LNode *head, int data);
LNode* LdeleteKey(LNode *head,int key);
int LinsertAfter(LNode *head, int insert_after, int data);
LNode* LdeleteEnd(LNode *head);
void LdeleteStart(LNode *head);
int LdeleteAfter(LNode *head, int delete_after);
void printLinkedList(LNode *head);
#endif // !SINGLY_H
