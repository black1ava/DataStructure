#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 10

struct Dequeue{
  int front, rear, items[SIZE];
};

typedef struct Dequeue dq;

void initDequeue(dq* q){
  q -> front = q -> rear = -1;
}

bool isFull(dq *q){
  return q -> front == 0 && q -> rear == SIZE - 1 ? true : false;
}

bool isEmpty(dq *q){
  return q -> front == -1 ? true : false;
}

void insertFront(dq *q, int newItem){
  if(isFull(q)){
    printf("Queue is full\n");
    return;
  }
  
  if(q -> front == -1){
    q -> front = q -> rear = 0;
    q -> items[q -> front] = newItem;
    return;
  }
  
  if(q -> rear != SIZE - 1){
    for(int i = q -> rear; i >= q -> front; i--){
      q -> items[i + 1] = q -> items[i];
    }
    q -> rear++;
    q -> items[q -> front] = newItem;
    return;
  }
  
  q -> front--;
  q -> items[q -> front] = newItem;
}

void deleteFront(dq *q){
  if(isEmpty(q)){
    printf("Queue is empty\n");
    return;
  }
  
  printf("Removed %d from the front queue\n", q -> items[q -> front]);
  
  if(q -> front == q -> rear){
    q -> front = q -> rear = -1;
    return;
  }
  
  q -> front++;
}

void insertRear(dq *q, int newItem){
  if(isFull(q)){
    printf("Queue is full\n");
    return;
  }
  
  if(q -> front == -1){
    q -> front = q -> rear = 0;
    q -> items[q -> rear] = newItem;
    return;
  }
  
  if(q -> front != 0){
    for(int i = q -> front; i <= q -> rear; i++){
      q -> items[i - 1] = q -> items[i];
    }
    q -> front--;
    q -> items[q -> rear] = newItem;
    return;
  }
  
  q -> rear++;
  q -> items[q -> rear] = newItem;
}

void deleteRear(dq *q){
  if(isEmpty(q)){
    printf("Queue is empty\n");
    return;
  }
  
  printf("Removed %d from the rear queue\n", q -> items[q -> rear]);
  
  if(q -> front == q -> rear){
    q -> front = q -> rear = -1;
    return;
  }
  
  q -> rear--;
}

void printQueue(dq *q){
  if(isEmpty(q)){
    printf("Queue is empty\n");
    return;
  }
  
  printf("Queue:\n");
  printf("Front: ");
  for(int i = q -> front; i <= q -> rear; i++){
    printf("%d ", q -> items[i]);
  }
  
  printf(" :Rear\n");
}

int main(){
  dq *q = (dq*)malloc(sizeof(dq));
  
  initDequeue(q);
  
  for(int i = 1; i <= 12; i++){
    insertRear(q, i);
  }
  
  printQueue(q);
  
  deleteFront(q);
  deleteFront(q);
  
  insertFront(q, 11);
  insertFront(q, 12);
  
  printQueue(q);
  
  deleteRear(q);
  deleteRear(q);
  
  insertRear(q, 13);
  insertRear(q, 14);
  
  printQueue(q);
  return 0;
}