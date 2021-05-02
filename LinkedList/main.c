#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct LinkedList{
  int value;
  struct LinkedList *next;
};

typedef struct LinkedList llt;

void printList(llt *head){

  printf("List: ");
  while(head != NULL){
    printf("%d ", head -> value);

    head = head -> next;
  }
  printf("\n");
}

int main(){
  llt *head = NULL;

  llt *one = NULL;
  llt *two = NULL;
  llt *three = NULL;

  one = (llt*)malloc(sizeof(llt));
  two = (llt*)malloc(sizeof(llt));
  three = (llt*)malloc(sizeof(llt));

  one -> value = 1;
  two -> value = 2;
  three -> value = 3;

  one -> next = two;
  two -> next = three;
  three -> next = NULL;

  head = one;

  printList(head);;

  return 0;
}