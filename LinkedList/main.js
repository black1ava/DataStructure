class LinkedNode{
  constructor(data){
    this.data = data;
    this.next;
  }
}

class LinkedList{
  constructor(head = null){
    this.head = head;
  }

  printList = () => {
    console.log("List: ");
    while(this.head !== null){
      console.log(this.head.data);
      this.head = this.head.next;
    }
  }
}

const one = new LinkedNode(1);
const two = new LinkedNode(2);
const three = new LinkedNode(3);

one.next = two;
two.next = three;
three.next = null;

const head = new LinkedList(one);

head.printList();