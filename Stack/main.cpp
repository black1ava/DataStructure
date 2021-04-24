#include<iostream>
using namespace std;

#define MAX 10

class Stack{
  private:
    int items[MAX];
    int top;
    
  public:
    Stack(){
      top = -1;
    }
    
    bool isFull(){
      return top == MAX - 1 ? true : false;
    }
    
    bool isEmpty(){
      return top == -1 ? true : false;
    }
    
    void push(int newItem){
      if(isFull()){
        cout << "Stack is full" << endl;
      }else{
        top++;
        items[top] = newItem;
      }
    }
    
    void pop(){
      if(isEmpty()){
        cout << "Stack is empty" << endl;
      }else{
        cout << "Removed " << items[top] << " from the stack" << endl;
        top--;
      }
    }
    
    void printStack(){
      cout << "Stacks ";
      for(int i = 0; i < top + 1; i++){
        cout << items[i] << " ";
      }
      
      cout << endl;
    }
};

int main(){
  Stack s;
  
  s.pop();
  
  cout << "After popping out" << endl;
  
  s.printStack();
  return 0;
}