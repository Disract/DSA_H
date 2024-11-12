#include <stdio.h>
#include <stdlib.h>



typedef struct LNode LNode;
struct LNode {
  int data;
  LNode *next;
};

LNode* createNode(int data){
  LNode *temp = (LNode*)malloc(sizeof(LNode));
  temp -> data = data;
  temp -> next = NULL;
  return temp;
}

void insertEnd(LNode *head, int data){
  LNode *temp = head;
  while(temp -> next != NULL){
    temp = temp -> next;
  }
  temp -> next = createNode(data);
}

LNode* insertStart(LNode *head, int data){
  LNode *temp = createNode(data);
  temp -> next = head;
  head = temp;
  return temp;
}

int insertAfter(LNode *head, int insert_after, int data){
  LNode *temp = head;
  while (temp -> data != insert_after && temp != NULL) {
    temp = temp -> next;
  }
  if(temp == NULL){
    return  -1;
  }
  else{
    LNode *node = createNode(data);
    node -> next = temp -> next;
    temp -> next = node;
    return 0;
  }
}

void deleteEnd(LNode *head){
  LNode *temp = head;
  while(temp -> next -> next != NULL)
    temp = temp -> next;
  temp -> next = NULL;
}

void deleteStart(LNode *head){
  head = head -> next;
}

int deleteAfter(LNode *head, int delete_after){
  LNode *temp = head;
  LNode *prev_temp;
  while(temp -> data != delete_after && temp != NULL){
    prev_temp = temp;
    temp = temp -> next;
  }
  if(temp == NULL)
    return -1;
  else {
    prev_temp -> next = temp -> next;
    temp = NULL;
    return 0;
  }
}

void printList(LNode *head){
  LNode *temp = head;
  while(temp -> next != NULL){
    printf("%d ", temp -> data);
    temp = temp -> next;
  }
}
