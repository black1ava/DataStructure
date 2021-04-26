class Deaueue{
  constructor(size){
    this.size = size;
    this.items = [];
    this.front = this.rear = -1;
  }
  
  isFull(){
    return this.front === 0 && this.rear === this.size - 1;
  }
  
  isEmpty(){
    return this.front === -1;
  }
  
  insertFront(newItem){
    if(this.isFull()){
      console.log('Queue is full');
    }else{
      if(this.front === -1){
        this.front = this.rear = 0;
        this.items[this.front] = newItem;
      }else{
        if(this.rear !== this.size - 1){
          for(let i = this.rear; i >= this.front; i--){
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
  
  deleteFront(){
    if(this.isEmpty()){
      console.log('Queue is empty');
    }else{
      console.log(`Removed ${ this.items[this.front] } from the front queue`);
      
      if(this.front === this.rear){
        this.front = this.rear = -1;
      }else{
        this.front++;
      }
    }
  }
  
  insertRear(newItem){
    if(this.isFull()){
      console.log('Queue is full');
    }else{
      if(this.front == -1){
        this.front = this.rear = 0;
        this.items[this.rear] = newItem;
      }else{
        if(this.front !== 0){
          for(let i = this.front; i <= this.rear; i++){
            this.items[i - 1] = this.items[i];
          }
          
          this.front--;
          this.items[this.rear] = newItem;
        }else{
          this.rear++;
          this.items[this.rear] = newItem;
        }
      }
    }
  }
  
  deleteRear(){
    if(this.isEmpty()){
      console.log('Queue is empty');
    }else{
      console.log(`Removed ${ this.items[this.rear]} from the rear queue`);
      
      if(this.front === this.rear){
        this.front = this.rear = -1;
      }else{
        this.rear--;
      }
    }
  }
  
  printQueue(){
    if(this.isEmpty()){
      console.log('Queue is empty');
    }else{
      console.log('Queue');
      console.log('Front');
      for(let i = this.front; i <= this.rear; i++){
        console.log(this.items[i]);
      }
      console.log('rear');
    }
  }
}

const q = new Deaueue(10);

for(let i = 1; i <= 12; i++){
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