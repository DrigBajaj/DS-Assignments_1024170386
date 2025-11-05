#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int flag = true;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] >arr[j+1]) {
            	flag=false;
            	int temp=arr[j];
            	arr[j]=arr[j+1];
            	arr[j+1]=temp;
            }
        }
		if (flag==true)
		break;
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
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    display(arr, n);
    return 0;
}
