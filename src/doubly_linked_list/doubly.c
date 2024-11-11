#include <stdio.h>
#include <stdlib.h>

struct DNode{
  int data;
  struct DNode *prev;
  struct DNode *next;
};

struct DNode* createNode(int data){
  struct DNode* temp = (struct DNode*) malloc(sizeof(struct DNode));
  temp -> prev = NULL;
  temp -> next = NULL;
  temp -> data = data;
  return temp;
}

void insertAtEnd(struct DNode *head, int data){
  struct DNode *ptr = head;
  while(ptr -> next != NULL){
    ptr = ptr -> next;
  }
  struct DNode *temp = createNode(data);
  ptr -> next = temp;
  temp -> prev = ptr;
}


struct DNode* insertAtBeg(struct DNode *head, int data){
  struct DNode *temp = createNode(data);
  temp -> next = head;
  head = temp;
  return head;
}


void insertAtMid(struct DNode *head, int insert_after, int data){
  struct DNode *ptr = head;
  while(ptr != NULL && ptr -> data != insert_after){
    ptr = ptr -> next;
  }
  if(ptr == NULL){
    printf("Cannot insert after element %d : %d does not exist in the dl\n", insert_after, insert_after);
  }
  else{
    struct DNode *temp = createNode(data);
    struct DNode *ptr2 = ptr -> next;
    temp -> prev = ptr;
    temp -> next = ptr -> next;
    temp -> data = data;
    ptr -> next = temp;
    ptr2 -> prev = temp;
  }
}



void printDL(struct DNode *head){
  struct DNode *ptr = head;
  while(ptr != NULL){
    printf("value: %d next address: 0x%x \n" , ptr -> data, ptr -> next);
    ptr = ptr -> next;
  }
}

int main(int argc, char *argv[])
{
  struct DNode *head = createNode(10);
  insertAtEnd(head, 23);
  insertAtEnd(head, 3);
  insertAtEnd(head, 13);
  insertAtEnd(head, 223);
  insertAtEnd(head, 1123);
  printDL(head);
  head =  insertAtBeg(head, 999);
  printf("\n\n");
  printDL(head);
  insertAtMid(head, 223, 1000);
  printf("\n\n");
  printDL(head);
  return 0;
}
