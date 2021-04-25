#include<iostream>
using namespace std;

#define SIZE 10

template <class T>

class CircularQueue{
  private:
    int items[SIZE];
    int front;
    int rear;

  public:
    CircularQueue(){
      cout << "Create a queue" << endl;
      front = rear = -1;
    }

    bool isFull(){
      return (front == 0 && rear == SIZE - 1) || front == rear + 1 ? true : false;
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

        rear = (rear + 1) % SIZE;
        items[rear] = newItem;
      }
    }

    void deQueue(){
      if(isEmpty()){
        cout << "Queue is empty" << endl;
      }else{

        cout << "Removed " << items[front] << " from the queue" << endl;
        if(front == rear){
          front = rear = -1;
        }else{
          front = (front + 1) % SIZE;
        }

      }
    }

    void printQueue(){
      if(isEmpty()){
        cout << "Queue is empty";
      }else{
        cout << "Queue ";
        int i;

        for(i = front; i != rear; i = (i + 1) % SIZE){
          cout << items[i] << " ";
        }

        cout << items[i];
      }

      cout << endl;
    }
};

int main(){

  CircularQueue<int> cq;

  cq.enQueue(1);
  cq.enQueue(2);
  cq.enQueue(3);
  cq.enQueue(4);
  cq.enQueue(5);
  cq.enQueue(6);
  cq.enQueue(7);
  cq.enQueue(8);
  cq.enQueue(9);
  cq.enQueue(10);

  cq.printQueue();

  cq.deQueue();
  cq.deQueue();

  cout << "After dequeue and enqueue 2 items" << endl;

  cq.enQueue(11);
  cq.enQueue(12);
  
  cq.printQueue();

  return 0;  
}