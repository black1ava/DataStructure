using System;

namespace CircularQueueCS{
  class Program{
    public class CircularQueue<T>{
      private static int size = 10;
      private int front;
      private int rear;
      private T[] items = new T[size];
      public CircularQueue(){
        this.front = this.rear = -1;
        Console.WriteLine("Queue is created");
      }

      public bool isFull(){
        return (this.front == 0 && this.rear == size - 1) || this.front == this.rear + 1 ? true : false;
      }

      public bool isEmpty(){
        return this.front == -1 ? true : false;
      }

      public void enQueue(T newItem){
        if(this.isFull()){
          Console.WriteLine("Queue is full");
        }else{
          if(this.front == -1){
            this.front = 0;
          }

          this.rear = (this.rear + 1) % size;
          this.items[this.rear] = newItem;
        }

      }
      public void deQueue(){
        if(this.isEmpty()){
          Console.WriteLine("Queue is empty");
        }else{

          Console.WriteLine("Removed {0} from the queue", this.items[this.front]);
          if(this.rear == this.front){
            this.rear = this.front = -1;
          }else{
            this.front = (this.front + 1) % size;
          }
        }
      }

      public void printQueue(){
        if(this.isEmpty()){
          Console.WriteLine("Queue is empty");
        }else{
          Console.Write("Queue ");
          int i;
          for(i = this.front; i != this.rear; i = (i + 1) % size){
            Console.Write("{0} ", this.items[i]);
          }
          Console.WriteLine("{0} ", this.items[i]);
        }
      }
    }
    static void Main(string[] args){
      CircularQueue<int> cq = new CircularQueue<int>();

      for(int i = 1; i <= 10; i++){
        cq.enQueue(i);
      }

      cq.printQueue();

      cq.deQueue();
      cq.deQueue();

      Console.WriteLine("After dequeue and enqueue 2 elements");

      cq.enQueue(11);
      cq.enQueue(12);

      cq.printQueue();
    }
  }
}