#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

// Queue structure
struct queue {
  int data[QUEUE_SIZE];
  int head;
  int tail;
};

// Initialize an empty queue
void init_queue(struct queue *q) {
  q->head = 0;
  q->tail = 0;
}

// Check if the queue is empty
int queue_empty(struct queue *q) {
  return q->head == q->tail;
}

// Check if the queue is full
int queue_full(struct queue *q) {
  return (q->tail + 1) % QUEUE_SIZE == q->head;
}

// Enqueue an element
void enqueue(struct queue *q, int x) {
  if (queue_full(q)) {
    printf("Error: queue is full\n");
    return;
  }
  q->data[q->tail] = x;
  q->tail = (q->tail + 1) % QUEUE_SIZE;
}

// Dequeue an element
int dequeue(struct queue *q) {
  if (queue_empty(q)) {
    printf("Error: queue is empty\n");
    return -1;
  }
  int x = q->data[q->head];
  q->head = (q->head + 1) % QUEUE_SIZE;
  return x;
}

int main() {
  struct queue q;
  init_queue(&q);

  // Enqueue some elements
  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);

  // Dequeue an element
  int x = dequeue(&q);
  printf("Dequeued element: %d\n", x);

  // Enqueue an element
  enqueue(&q, 4);

  // Dequeue all remaining elements
  while (!queue_empty(&q)) {
    x = dequeue(&q);
    printf("Dequeued element: %d\n", x);
  }

  return 0;
}
