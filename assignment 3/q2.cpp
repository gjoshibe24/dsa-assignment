#include <iostream>
#include <stack>
using namespace std;
string reverseString(string str) {
    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }
    string rev = "";
    while (!s.empty()) {
        rev += s.top();
        s.pop();
    }
    return rev;
}
int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    cout << "Original: " << str << endl;
    cout << "Reversed: " << reverseString(str) << endl;
    return 0;
}