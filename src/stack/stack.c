#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Stack;
struct Stack {
  int max_capacity;
  int top;
  int *stack;
};

Stack* createStack(int cap){
  Stack *temp = (Stack*) malloc(sizeof(Stack));
  temp -> max_capacity = cap;
  temp -> top = -1;
  temp -> stack = (int*) malloc(sizeof(int) * cap);
  return temp;
}

void push(Stack *stack, int to_insert){
  if(stack -> top + 1 <= stack -> max_capacity){
    stack -> stack[stack -> top++] = to_insert;
  }
  else{
    return ;
  }
}

int getTop(Stack *stack){
  return stack -> stack[stack -> top];
}

int pop(Stack *stack){
  int top = getTop(stack);
  stack -> top--;
  return top;
}
