#include<iostream>
using namespace std;
#include<queue>
class Mystack{
    queue<int>  q;
    public : 
    void push(int x){
        q.push(x);
        int n = q.size();
        for(int i = 0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    void pop(){
        cout<<"\nELEMENT AT TOP IS : ";
        cout<<q.front();
        q.pop();     
    }
};
int main(){
    Mystack s;
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