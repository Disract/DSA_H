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
DNode *deleteStart(DNode *head)
{
	if(head->next == NULL)
	{
		free(head);
		return NULL;
	}
	DNode *temp = head;
	head = head->next;
	temp->next->prev = NULL;
	free(temp);
	return head;
}
DNode *deleteEnd(DNode *head)
{
	if(head->next == NULL)
	{
		free(head);
		return NULL;
	}
	DNode *ptr = head;
	DNode *trail_ptr = NULL;
	while(ptr->next != NULL)
	{
		trail_ptr = ptr;
		ptr = ptr->next;
		if(ptr->next == NULL)
		{
			trail_ptr->next = NULL;
			free(ptr);
			return head;
		}
	}
	


}
DNode *deleteKey(DNode *head,int key)
{
	DNode *ptr = head;
	if(ptr->next == NULL)
	{
		free(head);
		return NULL;
	}
	else if(ptr->data == key)
	{
		return deleteStart(head);
	}
	while(ptr->next != NULL && ptr->data != key)
	{
		ptr = ptr->next;
	}
	if(ptr->next == NULL && ptr->data != key)
	{
		printf("NO SUCH KEY IN LIST\n");
		return head;
	}
	else if(ptr->next == NULL && ptr->data == key)
	{
		return deleteEnd(head);
	}
	else
	{
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		free(ptr);
		return head;
	}
	
}
void printDL(DNode *head){
  DNode *ptr = head;
  if(ptr == NULL)
  {
  	printf("NULL VALUE");
	return;
  }
  if(ptr->next == NULL)
  {
  	printf("%d",ptr->data);
	return;
  }
  while(ptr->next != NULL){
    printf("%d<->" , ptr -> data);
    ptr = ptr -> next;
    if(ptr->next == NULL)
    {
    	printf("%d",ptr->data);
    }
  }
}

