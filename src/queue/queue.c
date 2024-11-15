#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;
struct Queue {
  int queue_capacity;
  int *queue;
  int front;
  int back;
};

Queue* createQueue(int queue_capacity){
  Queue *temp = (Queue*) malloc(sizeof(Queue));
  temp -> queue_capacity = queue_capacity;
  temp -> queue = (int*) malloc(sizeof(int) * temp -> queue_capacity);
  temp -> front = 0;
  temp -> back = 0;
  return temp;
}

void enqueue(Queue *queue, int to_enqueue){
  if(queue -> back + 1 <= queue -> queue_capacity){
    queue -> queue[queue -> back++] = to_enqueue;
  }
  else{
    printf("Unable to add element to queue, maximum queue_capacity reached\n");
    return;
  }
}

int dequeue(Queue *queue){
  int de = queue -> queue[0];
  for(int i = 1; i <= queue -> back; i++){
    queue -> queue[i - 1] = queue -> queue[i];
  }
  return de;
}

