#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 10

struct Queue{
  int items[SIZE];
  int front, rear;
};

typedef struct Queue que;

void initQueue(que *q){

  q -> front = -1;
  q -> rear = -1;
}

bool isFull(que *q){
  return q -> rear == SIZE - 1 ? true : false;
}

bool isEmpty(que *q){
  return q -> front == -1 ? true : false;
}

void enQueue(que* q, int newItem){
  if(isFull(q)){
    printf("Queue if full\n");
  }else{
    if(q -> front == -1){
      q -> front = 0;
    }

    q -> rear++;
    q -> items[q -> rear] = newItem;
  }
}

void deQueue(que* q){
  if(isEmpty(q)){
    printf("Queue is empty\n");
  }else{
    printf("Removed %d from the queue\n", q -> items[q -> front]);
    q -> front++;

    if(q -> front > q -> rear){
      q -> front = q -> rear = -1;
    }
  }
}

void printQueue(que *q){
  if(isEmpty(q)){
    printf("Queue is empty");
  }else{
    printf("Queue ");
    for(int i = q -> front; i <= q -> rear; i++){
      printf("%d ", q -> items[i]);
    }
  }

  printf("\n");
}

int main(){

  que *q = (que *)malloc(sizeof(que));

  initQueue(q);

  enQueue(q, 1);
  enQueue(q, 2);
  enQueue(q, 3);

  printQueue(q);

  printf("After dequeuing out\n");

  deQueue(q);

  printQueue(q);

  return 0;
}