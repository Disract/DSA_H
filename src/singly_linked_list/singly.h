#ifndef SINGLY_H
#define SINGLY_H
typedef struct LNode LNode;
LNode* createNode(int data);
void insertEnd(LNode *head, int data);
LNode* insertStart(LNode *head, int data);
LNode* deleteKey(LNode *head,int key);
int insertAfter(LNode *head, int insert_after, int data);
LNode* deleteEnd(LNode *head);
void deleteStart(LNode *head);
int deleteAfter(LNode *head, int delete_after);
void printList(LNode *head);
#endif // !SINGLY_H
