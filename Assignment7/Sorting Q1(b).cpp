#include <iostream>
using namespace std;
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp=arr[i];
        int j=i;
        while(j>0 && arr[j-1]>temp){
        	arr[j]=arr[j-1];
        	j--;
		}
		arr[j]=temp;
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
    insertionSort(arr, n);
    cout << "Sorted array: ";
    display(arr, n);
    return 0;
}
