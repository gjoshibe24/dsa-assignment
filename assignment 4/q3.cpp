#include<iostream>
#include<stack>
using namespace std;
#define MAX 6

class MyQueue{  
    int front;
    int rear;
    int q[MAX];
    
public: 
    MyQueue(){  
        front = -1;
        rear = -1;
    }
    
    void enqueue(int x){
        if(front == (rear+1)%MAX){
            cout<<"\nQUEUE IS FULL \n";
        }else{
            if(front == -1){
                front = 0;
            }
            rear = (rear + 1)%MAX;
            q[rear] = x;
        }
    }
    
    int dequeue(){
        if(front == -1){
            cout<<"\n QUEUE IS EMPTY \n";
            return -1;
        }else{
            int temp = q[front];
            if(front == rear){
                front = rear = -1;
            }else{
                front = (front + 1)%MAX;
            }
            return temp;
        }
    }
    
    void display(){
        if(front == -1){
            cout << "Queue is empty";
            return;
        }
        int i = front;
        while(true){
            cout << q[i] << " ";
            if(i == rear) break;
            i = (i + 1)%MAX;
        }
    }
    
    int size(){
        if(front == -1) return 0;
        if(rear >= front) return rear - front + 1;
        else return (MAX - front) + (rear + 1);
    }
    
    bool isEmpty(){
        return front == -1;
    }
};

int main(){
    MyQueue q; 
    
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(20);
    q.enqueue(5);
    q.enqueue(9);
    
    int n = q.size();
    cout << "\nBefore interleave the queue is: \n";
    q.display();
    
    stack<int> s;
    
  
    for(int i = 0; i < n/2; i++){
        s.push(q.dequeue());
    }
    
 
    while(!s.empty()){
        q.enqueue(s.top());
        s.pop();
    }
    

    for(int i = 0; i < n/2; i++){
        q.enqueue(q.dequeue());
    }
    

    for(int i = 0; i < n/2; i++){
        s.push(q.dequeue());
    }
    

    while(!s.empty()){
        q.enqueue(s.top());  
        s.pop();
        q.enqueue(q.dequeue()); 
    }
    
    cout << "\nAfter interleaving the queue is: \n";
    q.display();
    
    return 0;
}