#include "bst.h"
#include <stdio.h>
int main(void)
{
  bstn *root = CreateBst(100);
  AddNode(50,root);
  AddNode(60,root);
  AddNode(40,root);
  DeleteNode(50,root);
  PrintIn(root);
}
