#include<iostream>
using namespace std;
#define MAX 10
class cirqueue{
    int q[MAX];
    int front ;
    int rear;
    public :
    cirqueue(){
        front=rear=-1;
    }
    bool isfull(){
        if(front == (rear+1)%MAX){
            return true;
        }else{
            return false;
        }
    }
    void enqueue(int x){
        if(isfull()){
            cout<<"\nOVERFLOW\n";
        }else {
            if(front==-1){
                front =0;
            }
            rear = (rear+1)%MAX;
            q[rear]=x;
        }
    }
    bool isempty(){
        if(front==-1){
            return true;
        }else{
            return false;
        }
    }
    void dequeue(){
        if(isempty()){
            cout<<"\nUNDERFLOW\n";
        }else if(front == rear){
            front  = rear = -1;
        }else{
            front = (front+1)%MAX;
        }
    }
    void peek(){
        if(isempty()){
            cout<<"\nQUEUE IS EMPTY\n";
        }else{
            cout<<"\nELEMENT AT FRONT IS :"<<q[front];
        }
    } 
    void display(){
        if(isempty()){
            cout<<"\nQUEUE IS EMPTY\n";
        }else{
            cout<<"\nQUEUE ITEMS ARE : \n";
            for(int i =front ;i!=rear;i = (i+1)%MAX){
                cout<<q[i]<<" ";
            }
            cout<<q[rear];
        }
    }
};
int main(){
    int ch;
    cirqueue Q;
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
                Q.dequeue();
                break;
            case 3 :
                if(Q.isempty()){
                    cout<<"\nQUEUE IS EMPTY\n";
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