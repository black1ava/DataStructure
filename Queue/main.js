class Queue{
  constructor(size){
    this.size = size;
    this.front = this.rear = -1;
    this.items = [];
  }

  isFull(){
    return this.rear === this.size -1 ? true : false;
  }

  isEmpty(){
    return this.front === -1 ? true : false;
  }

  enQueue(newItem){
    if(this.isFull()){
      console.log('Queue is full');
    }else{
      if(this.front === -1){
        this.front = 0;
      }

      this.rear++;
      this.items[this.rear] = newItem;
    }
  }

  deQueue(){
    if(this.isEmpty()){
      console.log('Queue is empty');
    }else{
      console.log(`Remove ${ this.items[this.front] } from the queue`);
      this.front++;

      if(this.front > this.rear){
        this.front = this.rear = -1;
      }
    }
  }

  printQueue(){
    if(this.isEmpty()){
      console.log("Queue is empty");
    }else{
      console.log("Queue ");
      for(let i = this.front; i <= this.rear; i++){
        console.log(this.items[i]);
      }
    }
  }
}

const q = new Queue(10);

q.enQueue(1);
q.enQueue(2);
q.enQueue(3);

q.printQueue();

console.log('After dequeueing');

q.deQueue();

q.printQueue();