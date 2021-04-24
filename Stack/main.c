#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10

int count = 0;

struct Stack{
  int items[MAX];
  int top;
};

typedef struct Stack stk;

void createEmptyStack(stk *s){
  s -> top = -1;
}

bool isFull(stk *s){
  return s -> top == MAX - 1 ? true : false;
}

bool isEmpty(stk *s){
  return s -> top == -1 ? true : false;
}

void push(stk *s, int newItem){
  if(isFull(s)){
    printf("Stack is full\n");
  }else{
    (s -> top)++;
    s -> items[s -> top] = newItem;
    count++;
  }
}

void pop(stk *s){
  if(isEmpty(s)){
    printf("Stack is empty\n");
  }else{
    printf("Removed %d from the stack\n", s -> items[s -> top]);
    (s -> top)--;
    count--;
  }
}

void printStack(stk *s){
  printf("Stacks ");
  for(int i = 0; i < count; i++){
    printf("%d ", s -> items[i]);
  }
  
  printf("\n");
}

int main(){
  
  stk *s = (stk *)malloc(sizeof(stk));
  
  createEmptyStack(s);
  
  push(s, 1);
  push(s, 2);
  push(s, 3);
  
  printStack(s);
  
  pop(s);
  
  printf("After popping out \n\n");
  
  printStack(s);
  
  return 0;
}