#include<stdio.h>
#include<stdlib.h>

struct LinkedList{
  int value;
  struct LinkedList *next;
};

typedef struct LinkedList ll;

void traverse(ll *head){
  ll *temp = head;

  while(temp != NULL){
    printf("%d --> ", temp -> value);

    temp = temp -> next;
  }

  printf("\n");
}

ll *insertFront(ll *head, int n){
  ll *temp = NULL;
  temp = (ll *)malloc(sizeof(ll));
  temp -> value = n;
  temp -> next = head;
  head = temp;

  return head;
}

ll *addEnd(ll *head, ll* n){
  if(head == NULL){
    head = n;

    return head;
  }

  head -> next = addEnd(head -> next, n);

  return head;
}

ll *insertEnd(ll *head, int n){
  ll *temp = (ll *)malloc(sizeof(ll));
  temp -> value = n;
  temp -> next = NULL;
  
  head = addEnd(head, temp);

  return head;
}

ll *addMiddle(ll *head, ll *n, int start, int position){
  if(start + 1 == position){
    n -> next = head -> next;
    head -> next = n;

    return head;
  }

  start++;
  head -> next = addMiddle(head -> next, n, start, position);

  return head;
}

ll *insertMiddle(ll *head, int n, int position){
  ll *temp = (ll *)malloc(sizeof(ll));
  temp -> value = n;
  temp -> next = NULL;

  head = addMiddle(head, temp, 0, position);

  return head;
}

ll *removeFront(ll *head){
  head = head -> next;
  return head;
}

ll *removeEnd(ll *head){
  if(head -> next == NULL){
    head = NULL;

    return head;
  }

  head -> next = removeEnd(head -> next);
  return head;
}

ll *deleteMiddle(ll *head, int start, int position){
  if(start + 1 == position){
    head -> next = head -> next -> next;
    return head;
  }

  start++;
  head -> next = deleteMiddle(head -> next, start, position);
  return head;
}

ll *removeMiddle(ll *head, int position){
  head = deleteMiddle(head, 0, position);

  return head;
}

int main(){
  ll *head = NULL;
  head = insertFront(head, 4);
  head = insertFront(head, 5);
  head = insertFront(head, 6);
  
  printf("Original: ");
  traverse(head);

  printf("Insert front: ");
  head = insertFront(head, 7);
  traverse(head);

  printf("Insert end: ");
  head = insertEnd(head, 8);
  traverse(head);

  printf("Insert middle: ");
  head = insertMiddle(head, 9, 2);
  traverse(head);

  printf("Remove front: ");
  head = removeFront(head);
  traverse(head);

  printf("Remove end: ");
  head = removeEnd(head);
  traverse(head);

  printf("Remove middle: ");
  head = removeMiddle(head, 2);
  traverse(head);

  return 0;
}