// package Stack;

public class Stack {

    int arr[] = null;
    int capacity = 100;
    int top = -1;
    int deleted;

    public Stack() {
        this.arr = new int[capacity];
    }

    public Stack(int capacity) {
        this.capacity = capacity;
        this.arr = new int [capacity];
    }

    public void push(int item) {
        if(isFull()) 
            System.out.println("Stack overflow!\nCan't push " + item + " to stack.");
        else {
            arr[++top] = item;
        }
    }

    public void pop() {
        if(isEmpty()) 
            System.out.println("Stack underflow!\nCan't pop anything.");
        else {
            deleted = arr[top--];
            System.out.println(deleted + " Poped...!");
        }
    }

    public boolean isEmpty() {
        if(top == -1) return true;
        else return false;
    }

    public boolean isFull() {
        if(top == capacity-1) return true;
        else return false; 
    }

    public void print() {
        if(isEmpty()) System.out.println("Nothing to print!");
        else {
            for(int i = top; i >= 0; i--) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
        }
    }

    public int size() {
        return top+1;
    }

    public int peek() {
        if(isEmpty()) return -1;
        return arr[top];
    }

    public static void main(String[] args) {

        Stack stack = new Stack(10);
        for(int i = 0; i < 10; i++) stack.push(i+10);
        stack.print();
        stack.pop();
        stack.print();
        stack.push(20);
        stack.push(21);
        // Stack stack = new Stack();
        // stack.pop();
        int peeked = stack.peek();
        if(peeked == -1) System.out.println("Nothing to peek!");
        else System.out.println(peeked + " peeked from the top position...!");

        System.out.println("Size of the Satck is : " + stack.size());
        
    }
}
