#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"\nEnter the order of Diagonal Matrix : ";
    cin>>n;
    int num;
    int arr[n];
    cout<<"\nEnter the diagonal elemments of a matrix : ";
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The Diagonal Matrix Is : \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout<<arr[i]<<" ";
            }else{
                cout<<"0"<<" ";
            }
        }
        cout<<endl;
    }
}

//(B)Tri-diagonal Matrix
#include<iostream>
using namespace std;
int main(){
    int n ;
    cout<<"\nenter the order of tridiagonal matrices : ";
    cin>>n;
    int arr[3*n-2];
    cout<<"\nenter the non zero elements of tridiagonal matrices : ";
    for(int i = 0;i<(3*n-2);i++){
        cin>>arr[i];
    }
    cout<<"\n the triadiagonal matrices is : ";
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(abs(i-j)<=1){
                cout<<arr[count]<<" ";
                count++;
            }else{
                cout<<"0"<<" ";
            }
        }
        cout<<endl;
    }
}

//(C) Lower triangular Matrix.
#include<iostream>
using namespace std;
int main(){
    cout<<"Enter the size of  lower triangular matrix: ";
    int n;
    cin>>n;
    int arr3[n*(n+1)/2];
    cout<<"Enter the non zero elements row wise: ";
    for(int i=0;i<n*(n+1)/2;i++){
        cin>>arr3[i];
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i-j>=0){
                cout<<arr3[count]<<" ";
                count+=1;
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<"\n";
    }
}

//(D)Upper triangular Matrix. 
#include<iostream>
using namespace std;
int main(){
    cout<<"Enter the size of  upper triangular matrix: ";
    int n;
    cin>>n;
    int arr3[n*(n+1)/2];
    cout<<"Enter the non zero elements row wise: ";
    for(int i=0;i<n*(n+1)/2;i++){
        cin>>arr3[i];
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j-i>=0){
                cout<<arr3[count]<<" ";
                count+=1;
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<"\n";
    }
}

//(E)Symmetric Matrix
#include<iostream>
using namespace std;
int main(){
    cout<<"Enter the size of symmetric matrix: ";
    int n;
    cin>>n;
    int arr5[n*(n+1)/2];
    cout<<"Enter the non zero elements row wise";
    for(int i=0;i<n*(n+1)/2;i++){
        cout<<": ";
        cin>>arr5[i];
    }
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                    int count1;
            if(j-i>=0){
                count1=i*n-(i*(i-1))/2+(j-i);
            }
            else{
                count1=j*n-(j*(j-1))/2+(i-j);
            }
            cout<<arr5[count1]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}