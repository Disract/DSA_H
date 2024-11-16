#include"bst.h"
#include<stdlib.h>
#include<stdio.h>
bstn* createNode(int data)
{
  bstn *temp = (bstn *)malloc(sizeof(bstn));
  temp->data = data;
  temp->right = NULL;
  temp->left = NULL;
  return temp;
}
bstn* createBST(int data)
{
	return createNode(data);
}
void AddNode(int data,bstn *head)
{
  bstn *temp = head;
  bstn *prev;
  while(temp != NULL){
    prev = temp;
    if(temp -> data > data)
      temp = temp -> left;
    else 
      temp = temp -> right;
  }
  if(prev -> data > data)
    prev -> left = createNode(data);
  else
    prev -> right = createNode(data);
}
bstn* SearchKey(bstn *head,int key)
{
	bstn *ptr_ = head;
	bstn *parent_ = ptr_;
	while(ptr_!=NULL && key != ptr_->data)
	{
		if(key<ptr_->data)
		{
			parent_ = ptr_;
			ptr_=ptr_->left;
		}
		else
		{	parent_ = ptr_;
			ptr_=ptr_->right;
		}
	}
	if(ptr_ != NULL)
	{
		return parent_;
	}
	else
	{
		return ptr_;
	}
}
bstn* MinKey(bstn *head)
{
	bstn *ptr_ = head;
	while(ptr_->left != NULL)
	{
		ptr_ = ptr_->left;
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
bstn* GetSuccesorParent(bstn *ptr)
{
	bstn *ptr_ = ptr->right;
	bstn *succesorparent_ = NULL;
	while(ptr_->left != NULL)
	{
		succesorparent_ = ptr_;
		ptr_ = ptr_->left;
	}
	return succesorparent_;
}
bstn* DeleteNode(int key,bstn *head)
{
	bstn *NodeToDeleteParent_ = SearchKey(head,key);
	if(NodeToDeleteParent_ == NULL)
	{
		printf("No Node Exist with the given key %d\n",key);
		return head;	
	}
	bstn *NodeToDelete_ = NULL;
	if(key>NodeToDeleteParent_->data)
	{
		NodeToDelete_ = NodeToDeleteParent_->right;
	}
	else if(key == NodeToDeleteParent_->data)
	{
		NodeToDelete_ = NodeToDeleteParent_;
	}
	else
	{
		NodeToDelete_ = NodeToDeleteParent_->left;
	}
	if(NodeToDelete_ -> right == NULL && NodeToDelete_ -> left == NULL)
	{

		if(NodeToDelete_->data<NodeToDeleteParent_->data)
		{
			NodeToDeleteParent_->left = NULL;
			free(NodeToDelete_);
			return head;
		}
		else if(NodeToDelete_->data == NodeToDeleteParent_->data)
		{
			free(NodeToDelete_);
			printf("YOUR TREE IS GONE\n");
			return NULL;
		}
		else
		{
			NodeToDeleteParent_->right = NULL;
			free(NodeToDelete_);
			return head;
		}
	}
	else if(NodeToDelete_->right!=NULL && NodeToDelete_->left==NULL)
	{
		if(NodeToDelete_->data<NodeToDeleteParent_->data)
		{
			NodeToDeleteParent_->left = NodeToDelete_->right;
			free(NodeToDelete_);
			return head;
		}
		else if(NodeToDelete_->data==NodeToDeleteParent_->data)
		{
			bstn *temp = NodeToDelete_->right;
			free(NodeToDelete_);
			return temp;
		}
		else
		{
			NodeToDeleteParent_->right = NodeToDelete_->right;
			free(NodeToDelete_);
			return head;
		}	
	}
	else if(NodeToDelete_->left != NULL && NodeToDelete_->right == NULL)
	{
		if(NodeToDelete_->data<NodeToDeleteParent_->data)
		{
			NodeToDeleteParent_->left = NodeToDelete_->left;
			free(NodeToDelete_);
			return head;
		}
		else if(NodeToDelete_->data==NodeToDeleteParent_->data)
		{
			bstn *temp = NodeToDelete_->left;
			free(NodeToDelete_);
			return temp;
		}
		else
		{
			NodeToDeleteParent_->right = NodeToDelete_->left;
			free(NodeToDelete_);
			return head;
		}
	}
	else if(NodeToDelete_->left != NULL && NodeToDelete_->right != NULL)
	{
		bstn *succesorParent_ = NodeToDelete_;
		if(NodeToDelete_->right == NULL)
		{
			bstn *succesor_ = NodeToDelete_->left;
			while(succesor_->right != NULL)
			{
				succesorParent_ = succesor_;
				succesor_ = succesor_->right;
			}
			NodeToDelete_->data = succesor_->data;
			if (succesorParent_->left == succesor_) 
			{
				succesorParent_->left = succesor_->right;
			}	 
			else 
			{
                        	succesorParent_->right = succesor_->right;
			}
			free(succesor_);
			return head;
		}
		else
		{
			bstn *successor_ = NodeToDelete_->right;
			while (successor_->left != NULL) 
			{
				succesorParent_ = successor_;
				successor_ = successor_->left;
			}
			NodeToDelete_->data = successor_->data;
			if (succesorParent_->left == successor_) 
			{
				succesorParent_->left = successor_->right;
			} 
			else 
			{
       				succesorParent_->right = successor_->right;
			}
                	free(successor_);
			return head;
		}
		
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
