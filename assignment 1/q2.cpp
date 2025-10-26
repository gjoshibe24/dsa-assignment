#include<iostream>
using namespace std;
void sort(int arr[],int &n){ //sorting
    for(int i = 0;i<n-1;i++){
        for (int j = 0; j< n-i-1; j++)
        {
           if(arr[j]>arr[j+1]){
            int temp;
            temp = arr[j];
            arr[j] =arr[j+1];
            arr[j+1] = temp;
           }
        }      
    }
    return;
}
int deletduplicate(int arr[],int &n){ //deleting duplicate 
     int i = 0;
     int j = 0;
     for(;i<n;i++){
        if(arr[i]!=arr[i+1]){
            arr[j]=arr[i];
            j++;
        }
     }
     return j;
}
int main(){
    cout<<"enter the elements of the array : ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"\nenter the elements of the array :"<<endl;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"array entered is "<<endl;
    for(int i =0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    sort(arr,n);
    cout<<"after sorting array is .....\n";
    for(int i =0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    n = deletduplicate(arr,n);
    cout<<"\nafter deletion the array is : \n";
    for(int i =0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}