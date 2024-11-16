#ifndef BST_LIB
#define BST_LIB
typedef struct bstn {
    struct bstn *right;
    struct bstn *left;
    int data;
} bstn;
bstn* CreateNode(int data);
bstn* createBST(int data);
void AddNode(int data,bstn *head);
void PrintIn(bstn *head);
void PrintPost(bstn *head);
void PrintPre(bstn *head);
bstn* DeleteNode(int key,bstn *head);
bstn* MinKey(bstn *head);
bstn* MaxKey(bstn *head);
bstn* GetSuccesorParent(bstn *head);
bstn* SearchKey(bstn *head,int key);
#endif

