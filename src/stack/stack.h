#ifdef STACK_H
#define STACK_H
typedef struct Stack Stack;
Stack* createStack(int cap);
void push(Stack *stack, int to_insert);
int getTop(Stack *stack);
int pop(Stack *stack);
#endif // STACK_H
