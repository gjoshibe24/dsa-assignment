#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    string postfix;
    cout<<"Enter the postfix expression you want to Evaluate : ";
    cin>>postfix;
    stack<int> s;
    for(int i = 0;i<postfix.length();i++){
        char c = postfix[i];
        if(c>='0'&&c<='9'){
            s.push(c-'0');
        }else{
            int val2 = s.top();
            s.pop();
            int val1 = s.top();
            s.pop();
            switch(c){
                case '+' : s.push(val1 + val2);break;
                case '-' : s.push(val1-val2);break;
                case '*' : s.push(val1*val2);break;
                case '/' : s.push(val1/val2);break;
                case '^' : s.push(val1^val2);break;
            }
        }
    }
    cout<<"\nRESULT OF EVALUATED POSTFIX EXPRESSION IS : ";
    cout<<s.top();
    return 0;
}