using System;

namespace LinkedListCS{
  class Program{
    public class LinkedNode{
      public Object value;
      public LinkedNode(Object value){
        this.value = value;
      }
      public LinkedNode next;
    }
    public class LinkedList{
      public LinkedNode head;
      public LinkedList(LinkedNode head){
        this.head = head;
      }
      public void printList(){
        Console.Write("List ");
        while(this.head != null){
          Console.Write("{0} ", this.head.value);
          this.head = this.head.next;
        }
        Console.WriteLine("");
      }
    }
    static void Main(string[] args){
      LinkedNode one = null;
      LinkedNode two = null;
      LinkedNode three = null;

      one = new LinkedNode(1);
      two = new LinkedNode("hi");
      three = new LinkedNode(3);

      one.next = two;
      two.next = three;
      three.next = null;
     
      LinkedList head = new LinkedList(one);
      head.printList();
    }
  }
}
