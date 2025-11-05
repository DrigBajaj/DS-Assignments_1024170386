#include <iostream>
using namespace std;
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min= j;
            }
        }
        if (min != i) {
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<"Entered array: ";
    display(arr,n);
    selectionSort(arr, n);
    cout << "Sorted array: ";
    display(arr, n);
    return 0;
}
