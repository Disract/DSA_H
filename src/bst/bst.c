#include"bst.h"
#include<stdlib.h>
#include<stdio.h>
bstn* CreateNode(int data)
{
  bstn *temp = (bstn *)malloc(sizeof(bstn));
  temp->data = data;
  temp->right = NULL;
  temp->left = NULL;
  return temp;
}
bstn* CreateBst(int data)
{
  return CreateNode(data);
}
void AddNode(int data,bstn *head)
{
    int addnodeflag_ = 0;
    bstn *ptr_ = head;
    while(addnodeflag_ != 1)
    {
      if(data<ptr_->data)
      {
        if(ptr_->left != NULL)
        {
          ptr_ = ptr_->left;
        }
        else
        {
          bstn *addnode_ = CreateNode(data);
          ptr_->left = addnode_;
          addnodeflag_ = 1;
        }
      }
      else
      {
        if(ptr_->right != NULL)
        {
          ptr_ = ptr_->right;
        }
        else
        {
          bstn *addnode_ = CreateNode(data);
          ptr_->right = addnode_;
          addnodeflag_ = 1;
        }
      }

    }
}
bstn* SearchKey(bstn *head,int key)
{
	bstn *ptr_ = head;
	bstn *parent_ = ptr_;
	while(ptr_!=NULL && key != ptr_->data)
	{
		if(key<ptr_->data)
		{
			parent_ = ptr;
			ptr_=ptr_->left;
		}
		else
		{	parent_ = ptr;
			ptr_=ptr_->right;
		}
	}
	return parent_;
}
bstn* MinKey(bstn *head)
{
	bstn *ptr_ = head;
	while(ptr_->left != NULL)
	{
		ptr_=ptr_->left;
	}
	return ptr_;
}
bstn* MaxKey(bstn *head)
{
	bstn *ptr_ = head;
	while(ptr_->right != NULL)
	{
		ptr_=ptr_->right;
	}
	return ptr_;
}
bstn* DeleteNode(bstn *head,int key)
{
	bstn *NodeToDeleteParent_ = SearchKey(head,key);
	bstn *NodeToDelete = NULL;
	if(key>NodeToDeleteParent_->data)
	{
		NodeToDelete = NodeToDeleteParent_->right;
	}
	else
	{
		NodeToDelete = NodeToDeleteParent_->left;
	}
	/*Actual Delteion*/
	if(NodeToDelete -> right == NULL && NodeToDelete -> left != NULL)
	{
		
	}
}
void PrintIn(bstn *head)
{
    bstn *tptr_ = head;
    if(tptr_ == NULL)
    {
      return;
    }
    PrintIn(tptr_->left);
    printf("%d ",tptr_->data);
    PrintIn(tptr_->right);
}
void PrintPost(bstn *head)
{
    bstn *tptr_ = head;
    if(tptr_ == NULL)
    {
      return;
    }
    PrintPost(tptr_->left);
    PrintPost(tptr_->right);
    printf("%d ",tptr_->data);
 }
void PrintPre(bstn *head)
{
    bstn *tptr_ = head;
    if(tptr_ == NULL)
    {
      return;
    }
    printf("%d ",tptr_->data);
    PrintPre(tptr_->left);
    PrintPre(tptr_->right);

}
