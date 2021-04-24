using System;

namespace QueueCS{
  class Program{
    public class Queue<T>{
      private int front;
      private int rear;
      static private int size = 10;
      private T[] items = new T[size];
      public Queue(){
        this.front = this.rear = -1;
      }

      public bool isFull(){
        return this.rear == size - 1 ? true : false;
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

          this.rear++;
          items[this.rear] = newItem;
        }
      }

      public void deQueue(){
        if(this.isEmpty()){
          Console.WriteLine("Queue is empty");
        }else{
          Console.WriteLine("Removed {0} from the queue", this.items[this.front]);
          this.front++;

          if(this.front > this.rear){
            this.front = this.rear = -1;
          }
        }
      }

      public void printQueue(){
        if(this.isEmpty()){
          Console.WriteLine("Queue is empty");
        }else{
          Console.Write("Queue ");
          for(int i = this.front; i <= this.rear; i++){
            Console.Write("{0} ", this.items[i]);
          }
        }

        Console.WriteLine("");
      }
    }
    static void Main(string[] args){
      Queue<int> q = new Queue<int>();

      q.enQueue(1);
      q.enQueue(2);
      q.enQueue(3);

      q.printQueue();

      Console.WriteLine("After dequeuing");

      q.deQueue();

      q.printQueue();
    }
  }
}
