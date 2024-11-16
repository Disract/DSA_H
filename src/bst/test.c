#include "bst.h"
#include <stdio.h>
int main(void)
{
  bstn *root = CreateBst(100);
  AddNode(50,root);
  AddNode(60,root);
  AddNode(40,root);
  AddNode(200,root);
  AddNode(890,root);
  AddNode(344,root);
  AddNode(15,root);
  AddNode(45,root);
  DeleteNode(45,root);
  DeleteNode(200,root);
  DeleteNode(50,root);
  DeleteNode(50,root);

  PrintIn(root);
  
}
