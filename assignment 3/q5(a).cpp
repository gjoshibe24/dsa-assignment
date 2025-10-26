#include<iostream>
using namespace std;
#include<queue>
class STACK{
    queue<int> q1,q2;
    public :
    void push(int x){
        if(q1.empty()){
            q1.push(x);
        }else{
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(x);
            while (!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }          
        }
    }
    void pop(){
        cout<<"\nelement at top of stack is : ";
        cout<<q1.front();
        q1.pop();
    }
};
int main(){
    STACK s;
    s.push(6);
    s.push(5);
    s.push(4);
    s.push(8);
    s.pop();
    s.pop();
    s.push(10);
    s.push(9);
    s.pop();
}