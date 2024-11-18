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


LNode* deleteEnd(LNode *head){
	if(head->next == NULL)
	{
		free(head);
		return NULL;
	}
  	LNode *temp = head;
  	LNode *trail_temp = NULL;
 	while(temp -> next  != NULL)
	{
		trail_temp = temp;
		temp = temp -> next;
	}
	trail_temp->next = NULL;
	free(temp);
	return head;

}

LNode* deleteStart(LNode *head){
	if(head == NULL)
	{
		return NULL;
	}
	LNode *temp = head;
	head = head -> next;
	free(temp);
	return head;
}

int deleteAfter(LNode *head, int delete_after){
  LNode *temp = head;
  LNode *prev_temp;
  while(temp -> data != delete_after && temp != NULL){
    prev_temp = temp;
    temp = temp -> next;
  }
  if(temp->next == NULL){
	printf("NO KEY AFTER %d\n",temp->data);
    	return -1;
  }
  else {
	
	prev_temp -> next = temp -> next;
    	free(temp);
    return 0;
  }
}

LNode* deleteKey(LNode *head,int key)
{
	LNode *ptr = head;
	LNode *trail_ptr;
	if(ptr->data == key)
	{
		return deleteStart(ptr);
	}
	while(ptr->next != NULL && ptr->data != key)
	{
		trail_ptr = ptr;
		ptr = ptr->next;
	}
	if(ptr->next == NULL && ptr->data == key)
	{
		head = deleteEnd(head);
		return head;
	}
	else if(ptr->next == NULL && ptr->data != key)
	{
		printf("NO SUCH KEY %d\n",key);
		return head;
	}
	trail_ptr->next = ptr->next;
	free(ptr);
	return head;
}

void printList(LNode *head){
  LNode *temp = head;
  if(temp == NULL)
  {
  	printf("NULL VALUE\n");
	return;
  }
  if(temp->next == NULL)
  {
  	printf("%d",temp->data);
	return;
  }
  while(temp -> next != NULL){
    printf("%d->", temp -> data);
    temp = temp -> next;
    if(temp->next == NULL)
    {
    	printf("%d",temp->data);
    }
  }
}
