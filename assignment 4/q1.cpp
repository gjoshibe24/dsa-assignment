#include<iostream>
using namespace std;
#define MAXLEN 10
class Queue{
    int q[MAXLEN];
    int front;
    int rear;
    public :
    Queue(){
        front = -1;
        rear = -1;
    }
    bool isfull(){
        if(rear >= (MAXLEN-1)){
            return true;
        }else{
            return false;
        }
    }
    void enqueue(int x){
        if(isfull()){
            cout<<"\nQUEUE IS FULL\n";
        }else if(front==-1 && rear == -1){
            front = rear =0;
            q[rear] = x;
        }else{
            rear = rear +1;
            q[rear] = x;
        }
    }
    bool isempty(){
        if(front == -1|| front > rear){
            return true;
        }else{
            return false ;
        }
    }
    int dqueue(){
        if(isempty()){
            cout<<"\nQUEUE IS EMPTY \n";
        }else if(front == 0&&rear ==0){
            front = rear = -1;
        }else{
            front ++;
        }
    }
    void peek(){
        if(isempty()){
            cout<<"\nQUEUE IS EMPTY\n";
        }else{
            cout<<"ITEM AT FRONT IS : "<<q[front];
        }
    }
    void display(){
        if(isempty()){
            cout<<"\nQUEUE IS EMPTY\n";
        }else{
            cout<<"\nITEMS OF OUEUE ARE :\n";
            for(int i = front;i<=rear;i++){
                cout<<q[i]<<" ";
            }
        }
    }
};
int main(){
    int ch;
    Queue Q;
    do{
        cout<<"\nENTER YOUR CHOICE TO PERFORM ON QUEUE : 1.enqueue()\t 2.dequeue()\t 3.isEmpty()\t 4.isFull()\t 5.display()\t 6.peek().\n";
        cin>>ch;
        switch(ch) 
        {
            case 1 :
                int x;
                cout<<"\nenter the value to enqueue : ";
                cin>>x;
                Q.enqueue(x);
                break;
            case 2 :
                Q.dqueue();
                break;
            case 3 :
                if(Q.isempty()){
                    cout<<"\nOUEUE IS EMPTY\n";
                }else{
                    cout<<"\nQUEUE IS NOT EMPTY \n";
                }
                break;
            case 4 :
                if(Q.isfull()){
                    cout<<"\nOUEUE IF FULL\n";
                }else{
                    cout<<"\nQUEUE IS NOT FULL \n";
                }
                break;
            case 5 :
                Q.display();
                break;
            case 6 :
                Q.peek();
                break;
            default :
                cout<<"\nPLEASE ENTER A VALID CHOICE \n";
                ch = 0;
        }
    }while(ch!=0);
return 0;
}