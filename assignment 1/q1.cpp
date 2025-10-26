#include<iostream>
using  namespace std;
int MAX_value = 100;
void creat(int arr[],int &n){
    cout<<"enter the number of element of an array"<<endl;
    cin>>n;
    if(n>MAX_value&&n<0){
        cout<<"enter a valid value.....";
        return;
    }
    cout<<"enter the elements of the array"<<endl;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    return;
}
void display(int arr[],int &n){
    cout<<"the values of entered array are "<<endl;
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return;
}
void insert(int arr[],int &n){
    cout<<"\nenter the position on which you want to insert : ";
    int pos;
    cin>>pos;
    if(pos>n || pos<1){
        cout<<"enter a valid position..";
        return;
    }
    cout<<"\nenter the new element you want to add : ";
    int newele;
    cin>>newele;
    for(int i = n;i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=newele;
    n++;
}
void delet(int arr[],int &n){
    cout<<"\nenter the position from which you want to delet element : ";
    int p;
    cin>>p;
    if(p>n || p<1){
        cout<<"enter a valid position....";
        return;
    }
    for(int i = p;i<n;i++){
        arr[i-1] = arr[i];
    }
    n--;
}
void linearsearch(int arr[],int &n){
    cout<<"\nenter the element you want to search for : ";
    int ele;
    cin>>ele;
    bool found = 0;
    for(int i = 0;i<n;i++){
        if(arr[i]==ele){
            cout<<ele<<" found at index = "<<i;
            found = 1;
            return;
        }
    }
    if(found == 0){
        cout<<"no such element found....."<<endl;
        return;
    }
}
int main(){
    int n;
    int arr[MAX_value];
    int ch;
    do{
        cout<<"enter your choice : ";
        cout<<" 1.creat \n2.display \n3.insert \n4.delet \n5.linearsearch \n6.EXIT"<<endl;
        cin>>ch;
        switch(ch){
        case 1 : 
            creat(arr,n);
            break;
        case 2 :
            display(arr,n);
            break;
        case 3 :
            insert(arr,n);
            break;
        case 4 :
            delet(arr,n);
            break;
        case 5 :
            linearsearch(arr,n);
            break;
        case 6 : 
            exit;
            break;
        default :
            cout<<"enter a valid choice......";           
        }
    }while(ch != 6);
    return 0;
}