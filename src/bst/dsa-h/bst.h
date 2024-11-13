#ifndef BST_LIB
#define BST_LIB
typedef struct bstn {
    struct bstn *right;
    struct bstn *left;
    int data;
} bstn;
bstn* CreateNode(int data);
bstn* CreateBst(int data);
void AddNode(int data,bstn *head);
void PrintIn(bstn *head);
void PrintPost(bstn *head);
void PrintPre(bstn *head);
bstn* DeleteNode(bstn *head,int key);
bstn* MinKey(bstn *head);
bstn* MaxKey(bstn *head);
bstn* SearchKey(bstn *head,int key);
#endif

