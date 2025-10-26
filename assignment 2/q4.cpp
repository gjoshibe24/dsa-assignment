#include <iostream>
#include <string>
using namespace std;
//concentrate one string to another
int main() {
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);
    string result = str1 + str2; // Concatenation
    cout << "Concatenated string: " << result << endl;
    return 0;
}

//(B)Write a program to reverse a string. 
#include <iostream>
#include <string>
using namespace std;
//reverse a string
int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    cout << "Reversed string: " << str << endl;
    return 0;
}

//(C)Write a program to delete all the vowels from the string. 
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    string result = "";
    cout<<"Enter the string : ";
    getline(cin, str);
    char vowels[]={'a','e','i','o','u','A','E','I','O','U'};
    int n = str.length();
    for(int i = 0;i<n;i++){
        bool is_vowel = false;
        for(int j =0;j<10;j++){
            if(str[i]==vowels[j]){
                is_vowel = true;
                break;
            }
        }
        if(is_vowel!=true){
            result+=str[i];
        }     
    }
    cout<<"\nString after removal of vowels is : "<<result;
}

//(D)Write a program to sort the strings in alphabetical order.
#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    int n = str.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                // swap
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    cout << "String after sorting characters: " << str << endl;
    return 0;
}

//(E)Write a program to convert a character from uppercase to lowercase.
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"enter the string : ";
    cin>>str;
    int n = str.length();
    for(int i = 0;i<n;i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i]=str[i]+32;
        }
    }
    cout<<"After conversion of uppercse to lower case the string is : "<<str;
}