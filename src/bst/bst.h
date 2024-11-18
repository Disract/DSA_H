#ifndef BST_LIB
#define BST_LIB
typedef struct bstn {
    struct bstn *right;
    struct bstn *left;
    int data;
} bstn;
bstn* createNode(int data);
bstn* createBST(int data);
void addNode(int data,bstn *head);
void printIn(bstn *head);
void pintPost(bstn *head);
void printPre(bstn *head);
bstn* deleteNode(int key,bstn *head);
bstn* minKey(bstn *head);
bstn* maxKey(bstn *head);
bstn* getSuccesorParent(bstn *head);
bstn* searchKey(bstn *head,int key);
#endif

