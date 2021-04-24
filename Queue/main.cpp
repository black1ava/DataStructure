#include<iostream>
using namespace std;

template <class T>

#define SIZE 10

class Queue{
  private:
    int front, rear; 
    T items[SIZE];
  public:
    Queue(){
      front = rear = -1;
    }

    bool isFull(){
      return rear ==  SIZE  -1 ? true : false;
    }

    bool isEmpty(){
      return front == -1 ? true : false;
    }

    void enQueue(T newItem){
      if(isFull()){
        cout << "Queue is full" << endl;
      }else{
        if(front == -1){
          front = 0;
        }

        rear++;
        items[rear] = newItem;
      }
    }

    void deQueue(){
      if(isEmpty()){
        cout << "Queue is empty" << endl;
      }else{
        cout << "Removed " << items[front] << " from the queue" << endl;

        front++;

        if(front > rear){
          front = rear = -1;
        }
      }
    }

    void printQueue(){
      if(isEmpty()){
        cout << "Queue is empty" << endl;
      }else{
        cout << "Queue ";
        for(int i = front; i <= rear; i++){
          cout << items[i] << " ";
        }
      }

      cout << endl;
    }
};

int main(){
  Queue<string> q;

  q.enQueue("Hello");
  q.enQueue("World");
  q.enQueue("!");

  q.printQueue();

  cout << "After dequeuing" << endl;

  q.deQueue();

  q.printQueue();

  return 0;
}