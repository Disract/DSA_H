#include <stdio.h>
#include <stdlib.h>

typedef struct DNode DNode;

typedef struct DNode{
  int data;
  DNode *prev;
  DNode *next;
}DNode;

DNode* createNode(int data){
  DNode* temp = (DNode*) malloc(sizeof(DNode));
  temp -> prev = NULL;
  temp -> next = NULL;
  temp -> data = data;
  return temp;
}

void insertEnd(DNode *head, int data){
  DNode *ptr = head;
  while(ptr -> next != NULL){
    ptr = ptr -> next;
  }
  DNode *temp = createNode(data);
  ptr -> next = temp;
  temp -> prev = ptr;
}


DNode* insertStart(DNode *head, int data){
  DNode *temp = createNode(data);
  temp -> next = head;
  head = temp;
  return head;
}


void insertAfter(DNode *head, int insert_after, int data){
  DNode *ptr = head;
  while(ptr != NULL && ptr -> data != insert_after){
    ptr = ptr -> next;
  }
  if(ptr == NULL){
    printf("Cannot insert after element %d : %d does not exist in the dl\n", insert_after, insert_after);
  }
  else{
    DNode *temp = createNode(data);
    DNode *ptr2 = ptr -> next;
    temp -> prev = ptr;
    temp -> next = ptr -> next;
    temp -> data = data;
    ptr -> next = temp;
    ptr2 -> prev = temp;
  }
}



void printDL(DNode *head){
  DNode *ptr = head;
  while(ptr != NULL){
    printf("value: %d next address: 0x%x \n" , ptr -> data, ptr -> next);
    ptr = ptr -> next;
  }
}

