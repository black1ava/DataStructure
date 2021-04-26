using System;

namespace DequeueCS
{
  class Program{
    public class Dequeue<T>{
      private static int size = 10;
      private int front;
      private int rear;
      private T[] items = new T[size];
      public Dequeue(){
        Console.WriteLine("Create a queue");
        this.front = this.rear = -1;
      }
      public bool isFull(){
        return this.front == 0 && this.rear == size - 1;
      }
      public bool isEmpty(){
        return this.front == -1;
      }
      public void insertFront(T newItem){
        if(this.isFull()){
          Console.WriteLine("Queue is full");
        }else{
          if(this.front == -1){
            this.front = this.rear = 0;
            this.items[this.front] = newItem;
          }else{
            if(this.rear != size - 1){
              for(int i = this.rear; i >= this.front; i--){
                this.items[i + 1] = this.items[i];
              }
              this.items[this.front] = newItem;
              this.rear++;
            }else{
              this.front--;
              this.items[this.front] = newItem;
            }
          }
        }
      }
      public void deleteFront(){
        if(this.isEmpty()){
          Console.WriteLine("Queue is empty");
        }else{

          Console.WriteLine("Removed {0} from the front queue", this.items[this.front]);

          if(this.front == this.rear){
            this.front = this.rear = -1;
          }else{
            this.front++;
          }
        }
      }
      public void insertRear(T newItem){
        if(this.isFull()){
          Console.WriteLine("Queue is full");
        }else{
          if(this.front == -1){
            this.front = this.rear = 0;
            this.items[this.rear] = newItem;
          }else{
            if(this.front != 0){
              for(int i = this.front; i <= this.rear; i++){
                this.items[i - 1] = this.items[i];
              }
              this.items[this.rear] = newItem;
              this.front--;
            }else{
              this.rear++;
              this.items[this.rear] = newItem;
            }
          }
        }
      }

      public void deleteRear(){
        if(this.isEmpty()){
          Console.WriteLine("Queue is empty");
        }else{
          Console.WriteLine("Delete {0} from the rear queue", this.items[this.rear]);

          if(this.front == this.rear){
            this.front = this.rear = -1;
          }else{
            this.rear--;
          }
        }
      }

      public void printQueue(){
        if(this.isEmpty()){
          Console.WriteLine("Queue is empty");
        }else{
          Console.Write("Front queue: ");
          for(int i = this.front; i <= this.rear; i++){
            Console.Write("{0} ", this.items[i]);
          }
          Console.WriteLine(" :Rear queue");
        }
      }
    }
    static void Main(string[] args){
      Dequeue<int> q = new Dequeue<int>();

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
    }
  }
}