#include<iostream>
using namespace std;
void reverse(int arr[],int &n){
    int i =0;
    while(i <= (n-i-1) ){
        int temp ;
        temp = arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
        i++;
    }
    return;
}
int main(){
    cout<<"enter number of elements in the array :" ;
    int n;
    cin>>n;
    int arr[n];
    cout<<"\nenter the elements of the array : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\nafter reversing the array is \n";
    reverse(arr,n);
     for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}

//B->
#include <iostream>
using namespace std;
int main() {
    int r1, r2, c1, c2;
    cout << "\nEnter the number of rows of the first matrix: ";
    cin >> r1;
    cout << "\nEnter the number of columns of the first matrix: ";
    cin >> c1;
    cout << "\nEnter the number of rows of the second matrix: ";
    cin >> r2;
    cout << "\nEnter the number of columns of the second matrix: ";
    cin >> c2;
    // To Check if multiplication is possible
    if (c1 != r2) {
        cout << "Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
        return 1;
    }
    int arr1[r1][c1], arr2[r2][c2];
    cout << "\nEnter first matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> arr1[i][j];
        }
    }
    cout << "\nEnter second matrix:\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> arr2[i][j]; // Corrected to arr2
        }
    }
    int arr3[r1][c2];
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            arr3[i][j] = 0; // Initialize to zero
        }
    }
    // Matrix multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    cout << "After multiplication, the resultant matrix is:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << "arr[" << i << "][" << j << "] = " << arr3[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}

//c->
#include <iostream>
using namespace std;
int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    int matrix[10][10];
    int transpose[10][10];
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];  // Swap row and column indices
        }
    }
    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nTransposed Matrix:\n";
    for (int i = 0; i < cols; i++) {  // Note rows and cols are swapped
        for (int j = 0; j < rows; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}