#include<iostream>
#include<stack>
#include<string>
using namespace std;
int prec(char c){
    if(c=='^') return 3;
    else if(c=='*'||c=='/') return 2;
    else if(c=='-'||c=='+') return 1;
    return 0;
}
int main(){
    string infix,postfix;
    cout<<"\nEnter Infix Expression : ";
    cin>>infix;
    postfix = "";
    stack<char> s;
    for(int i =0;i<infix.length();i++){
        char c = infix[i];
        if((c>='a'&&c<='z')||(c>='A'&&c<='B')||(c>='0'&&c<='9')){
            postfix+=c;
        }else if(c=='('){
            s.push(c);
        }else if(c==')'){
            while(!s.empty()&&s.top()!='('){
                postfix+=s.top();
                s.pop();
            }
            s.pop();
        }else{
            while(!s.empty()&&(prec(s.top()))>=prec(c)){
                postfix+=s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }
    cout<<"\npostfix expertion is : "<<postfix;
    return 0;
}