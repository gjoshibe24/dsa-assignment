#include <iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter the number of elements of array: ";
    cin>>num;
    int arr[num];
    cout<<"\nEnter elements of the array\n";
    for (int i=0;i<num;i++){
        cin>>arr[i];
    }
    int distinct_elements=0;
    for(int i=0;i<num;i++){
        bool found=false;
        for (int j=i+1;j<num;j++){
            if(arr[i]==arr[j]){
                found=true;
                break;
            }
        }
        if (found==false){
            distinct_elements+=1;
        }
    }
    cout<<"Distinct elements: "<<distinct_elements;
    return 0;
}