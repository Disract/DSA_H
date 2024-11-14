#include "bst.h"
#include <stdio.h>
int main(void)
{
  bstn *root = CreateBst(10);
  AddNode(50,root);
  AddNode(20,root);
  PrintIn(root);
}
