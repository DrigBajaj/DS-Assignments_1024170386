#include <iostream>
using namespace std;
void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    int* count = new int[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " non-negative integers: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout<<"Entered array: ";
    display(arr,n);
    countingSort(arr,n);
    cout << "Sorted array: ";
    display(arr,n);
    return 0;
}

