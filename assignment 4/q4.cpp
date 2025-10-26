#include <iostream>
#include <queue>
using namespace std;
void firstNonRepeating(string str) {
    int count[26] = {0};     
    queue<char> q;           
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        q.push(ch);
        count[ch - 'a']++;
        while (!q.empty() && count[q.front() - 'a'] > 1) {
            q.pop();  
        }
        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout << -1 << " ";
        }
    }
    cout << endl;
}
int main() {
    string input = "aabc";   
    firstNonRepeating(input);
    return 0;

}