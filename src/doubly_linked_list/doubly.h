#ifndef DOUBLY_H
typedef struct DNode DNode;
DNode* createNode(int data);
DNode* deleteEnd(DNode *head);
DNode* deleteStart(DNode *head);
DNode* deleteKey(DNode *head,int data);
void insertEnd(DNode *head, int data);
void insertStart(DNode *head, int data);
void insertAfter(DNode *head, int insert_after, int data);
void printDL(DNode *head);
#endif // !DOUBLY_H
