class Stack{
  constructor(size){
    this.size = size;
    this.items = [];
    this.top = -1;
  }
  
  isFull(){
    return this.top === this.size - 1 ? true : false;
  }
  
  isEmpty(){
    return this.top === -1 ? true : false;
  }
  
  pushItem(newItem){
    if(this.isFull()){
      console.log("Stack is full");
    }else{
      this.top++;
      this.items.push(newItem);
    }
  }
  
  popItem(){
    if(this.isEmpty()){
      console.log("Stack is empty");
    }else{
      console.log(`Removed ${ this.items[this.top] } from the stack`);
      this.top--;
      this.items.pop();
    }
  }
  
  printStack(){
    console.log("Stack ");
    this.items.forEach(item => {
      console.log(item);
    });
  }
}

const st = new Stack(10);

st.pushItem(1);
st.pushItem(2);
st.pushItem(3);

st.printStack();

console.log('After popping out');

st.popItem();

st.printStack();