#ifndef QUEUE_H
#define QUEUE_H
typedef struct Queue Queue;
Queue* createQueue(int queue_capacity);
void enqueue(Queue *queue, int to_enqueue);
int dequeue(Queue *queue);
#endif // !QUEUE_H

