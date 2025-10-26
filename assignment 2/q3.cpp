#include <iostream>
using namespace std;
int findMissingNumber(int arr[], int n) {
    int total = (n + 1) * (n)/ 2; 
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return total - sum; 
}
int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8}; // Missing 5
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Missing number is: " << findMissingNumber(arr, n) << endl;
    return 0;
}