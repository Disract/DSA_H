#include<stdio.h>
#include "singly.h"
int main()
{
	LNode* head = createNode(10);
	insertAfter(head,10,20);
	insertAfter(head,20,30);
	insertAfter(head,30,40);
	head = deleteKey(head,10);
	insertEnd(head,50);
	deleteAfter(head,50);
	head = deleteKey(head,20);
	head = deleteKey(head,40);
	head = deleteKey(head,50);
	head = deleteKey(head,70);
	insertEnd(head,80);
	head = deleteEnd(head);
	head = deleteEnd(head);
	
	printList(head);
}
