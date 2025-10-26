#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"enter rows of the matrix....";
    cin>>r;
    cout<<"enter columns of the matrix....";
    cin>>c;
    int arr[r][c];
    cout<<"enter the matrix \n";
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin>>arr[i][j];
        }
    }
     cout<<"entered  matrix is  \n";
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int sr,sc;
    for(int i =0;i<r;i++){
        sr=0;
        for(int j=0;j<c;j++){
            sr+=arr[i][j];           
        }
        cout<<i+1<<" sum of row = "<<sr<<endl;     
    }
        for(int i =0;i<c;i++){
        sc=0;
        for(int j=0;j<r;j++){
            sc+=arr[j][i];            
        }
        cout<<i+1<<" sum of column = "<<sc<<endl;     
    }
    return 0;
}