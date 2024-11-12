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

