#include<iostream>
using namespace std;

template <class T>

class LinkedList{
  public:
    T value;
    LinkedList *next;

    void printList(){
      LinkedList *head = this;
      cout << "List ";
      while(head != NULL){
        cout << head -> value << " ";
        head = head -> next;
      }
      cout << endl;
    }
};

int main(){
  LinkedList<int> *head;

  LinkedList<int> *one, *two, *three = NULL;;

  one = new LinkedList<int>();
  two = new LinkedList<int>();
  three = new LinkedList<int>();
 
  one -> value = 1;
  two -> value = 2;
  three -> value = 3;

  one -> next = two;
  two -> next = three;
  three -> next = NULL;

  head = one;

  head -> printList();

  return 0;
}