#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int start = 0, end = n - 1;

    while (start < end) {
        int minIndex = start;
        int maxIndex = start;

        // Find min and max in the remaining unsorted part
        for (int i = start; i <= end; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Place the minimum at the start
        swap(arr[start], arr[minIndex]);

        // If we swapped the max element earlier (from start), update its index
        if (maxIndex == start)
            maxIndex = minIndex;

        // Place the maximum at the end
        swap(arr[end], arr[maxIndex]);

        start++;
        end--;
    }
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    improvedSelectionSort(arr, n);

    cout << "\nSorted Array: ";
    display(arr, n);

    return 0;
}
