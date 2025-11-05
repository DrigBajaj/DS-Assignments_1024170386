#include <iostream>
using namespace std;
void improvedSelectionSort(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    while (start < end) {
        int minIndex = start;
        int maxIndex = start;
        for (int i = start; i <= end; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }
        int temp = arr[start];
        arr[start] = arr[minIndex];
        arr[minIndex] = temp;
        if (maxIndex == start)
            maxIndex = minIndex;
        temp = arr[end];
        arr[end] = arr[maxIndex];
        arr[maxIndex] = temp;
        start++;
        end--;
    }
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
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
	cout<<"Entered array: ";
	display(arr,n);
    improvedSelectionSort(arr, n);
    cout << "Sorted array: ";
    display(arr,n);
    return 0;
}
