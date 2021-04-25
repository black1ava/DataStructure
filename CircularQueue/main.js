class CircularQueue{
  constructor(size){
    this.size = size;
    this.front = -1;
    this.rear = -1;
    this.items = [];
    
    console.log('Queue is created');
  }
  
  isFull(){
    return (this.front === 0 && this.rear === this.size - 1) || this.rear === this.front - 1 ? true : false;
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
      
      this.rear = (this.rear + 1) % this.size;
      
      this.items[this.rear] = newItem;
    }
  }
  
  deQueue(){
    if(this.isEmpty()){
      console.log('Queue is empty');
    }else{
      console.log(`Removed ${ this.items[this.front]} from the queue`);
      
      if(this.front === this.rear){
        this.rear = this.front = -1;
      }else{
        this.front = (this.front + 1) % this.size;
      }
    }
  }
  
  printQueue(){
    if(this.isEmpty()){
      console.log('Queue is empty');
    }else{
      let i;
      console.log("Queue");
      for(i = this.front; i != this.rear; i = (i + 1) % this.size){
        console.log(this.items[i]);
      }
      console.log(this.items[i]);
    }
  }
}

const cq = new CircularQueue(10);
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

cq.enQueue(11);
cq.enQueue(12);

console.log('After dequeue and enqueue 2 items');

cq.printQueue();