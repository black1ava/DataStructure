#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 10

struct CircularQueue{
  int items[10];
  int front, rear;
};

typedef struct CircularQueue ccq;

void initCircular(ccq *cq){
  cq -> front = cq -> rear = -1;
}

bool isFull(ccq *cq){
  return (cq -> front == 0 && cq -> rear == SIZE - 1) || cq -> front == cq -> rear + 1 ? true : false;
}

bool isEmpty(ccq *cq){
  return cq -> front == -1;
}

void enQueue(ccq *cq, int newItem){
  if(isFull(cq)){
    printf("Queue is full\n");
  }else{
    if(cq -> front == -1){
      cq -> front = 0;
    }

    cq -> rear = (cq -> rear + 1) % SIZE;

    cq -> items[cq -> rear] = newItem; 
  }
}

void deQueue(ccq *cq){
  if(isEmpty(cq)){
    printf("Queue is empty\n");
  }else{

    printf("Removed %d from the queue\n", cq ->  items[cq -> front]);
    if(cq -> front == cq -> rear){
      cq -> front = cq -> rear = -1;
    }

    cq -> front = (cq -> front + 1) % SIZE;
  }
}

void printQueue(ccq *cq){
  if(isEmpty(cq)){
    printf("Queue is empty");
  }else{
    printf("Queue ");
    int i;
    for(i = cq -> front; i != cq -> rear; i = (i + 1) % SIZE){
      printf("%d ", cq -> items[i]);
    }
    printf("%d ", cq -> items[i]);
  }
  printf("\n");
}

int main(){
  ccq *cq = (ccq*)malloc(sizeof(ccq));

  initCircular(cq);

  enQueue(cq, 1);
  enQueue(cq, 2);
  enQueue(cq, 3);
  enQueue(cq, 4);
  enQueue(cq, 5);
  enQueue(cq, 6);
  enQueue(cq, 7);
  enQueue(cq, 8);
  enQueue(cq, 9);
  enQueue(cq, 10);

  printQueue(cq);

  deQueue(cq);
  deQueue(cq);

  enQueue(cq, 11);
  enQueue(cq, 12);

  printf("After dequeue and enqueue 2 elements\n");

  printQueue(cq);

  return 0;
}