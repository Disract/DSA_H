#include"doubly.h"
#include<stdio.h>
int main()
{
	DNode *head = createNode(10);
	insertEnd(head,20);
	insertEnd(head,30);
	insertEnd(head,40);
	insertEnd(head,50);
	insertEnd(head,60);
	head = deleteKey(head,10);
	head = deleteKey(head,50);
	head = deleteKey(head,30);
	head = deleteKey(head,40);
	head = deleteKey(head,20);
	head = deleteStart(head);
	printDL(head);
}
