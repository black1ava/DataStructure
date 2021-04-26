#include<iostream>
using namespace std;

#define SIZE 10

template <class T>

class Dequeue{
  private:
    int front, rear;
    T items[SIZE];

  public:
    Dequeue(){
      front = rear = -1;
      cout << "Create a queue" << endl;
    }

    bool isFull(){
      return front == 0 && rear == SIZE - 1 ? true : false;
    }

    bool isEmpty(){
      return front == -1 ? true : false;
    }

    void insertFront(T newItem){
      if(isFull()){
        cout << "Queue is full" << endl;
        return;
      }

      if(front == -1){
        front = rear = 0;
        items[front] = newItem;
        return;
      }

      if(rear != SIZE - 1){
        for(int i = rear; i >= front; i--){
          items[i + 1] = items[i];
        }
        rear++;
        items[front] = newItem;
        return;
      }

      front--;
      items[front] = newItem;
    }

    void deleteFront(){
      if(isEmpty()){
        cout << "Queue is empty" << endl;
        return;
      }

      cout << "Removed " << items[front] << " from the front queue" << endl;
      if(front == rear){
        front = rear = -1;
        return;
      }

      front++;
    }

    void insertRear(T newItem){
      if(isFull()){
        cout << "Queue is full" << endl;
        return;
      }

      if(front == -1){
        front = rear = 0;
        items[rear] = newItem;
        return;
      }

      if(front != 0){
        for(int i = front; i <= rear; i++){
          items[i - 1] = items[i];
        }
        
        front--;
        items[rear] = newItem;
        return;
      }

      rear++;
      items[rear] = newItem;
    }

    void deleteRear(){
      if(isEmpty()){
        cout << "Queue is empty" << endl;
        return;
      }

      cout << "Remove " << items[rear] << " from the rear queue" << endl;

      if(front == rear){
        front = rear = -1;
        return;
      }

      rear--;
    }

    void printQueue(){
      if(isEmpty()){
        cout << "Queue is empty" << endl;
        return;
      }

      cout << "Queue " << endl;
      cout << "Front: ";

      for(int i = front; i <= rear; i++){
        cout << items[i] << " ";
      }

      cout << " :Rear";
      cout << endl;
    }
};

int main(){
  Dequeue<int> q;
  
  for(int i = 1; i <= 12; i++){
    q.insertFront(i);
  }

  q.printQueue();

  q.deleteFront();
  q.deleteFront();

  q.insertFront(11);
  q.insertFront(12);

  q.printQueue();

  q.deleteRear();
  q.deleteRear();

  q.insertRear(13);
  q.insertRear(14);

  q.printQueue();

  return 0;
}