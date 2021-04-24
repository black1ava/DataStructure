using System;

namespace StackCS{
  class Program{

    class Stack{
      private static int size = 10;
      private int[] items = new int[size];
      private int top;

      public Stack(){
        this.top = -1;
      }

      public bool isFull(){
        return this.top == size - 1 ? true : false;
      }

      public bool isEmpty(){
        return this.top == -1 ? true : false;
      }

      public void push(int newItem){
        if(this.isFull()){
          Console.WriteLine("Stack is full");
        }else{
          this.top++;
          items[this.top] = newItem;
        }
      }

      public void pop(){
        if(this.isEmpty()){
          Console.WriteLine("Stack is empty");
        }else{
          Console.WriteLine("Removed {0} from the stack", this.items[this.top]);
          this.top--;
        }
      }

      public void printStack(){
        Console.Write("Stack ");
        for(int i = 0; i < this.top + 1; i++){
          Console.Write("{0} ", this.items[i]);
        }

        Console.WriteLine("");
      }
    }
    static void Main(string[] args){
      Stack st = new Stack();

      st.push(1);
      st.push(2);
      st.push(3);

      st.printStack();

      Console.WriteLine("After popping out");
      st.pop();

      st.printStack();

    }
  }
}
