#include <iostream>
#include <cstdlib>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[100];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the difference value k: ";
    cin >> k;
    cout << "\nInput array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int i = 0, j = 1;
    int count = 0;
    cout << "Pairs with difference " << k << ": ";
    while (j < n && i < n) {
        int diff = arr[j] - arr[i];
        if (diff == k) {
            cout << "(" << arr[i] << ", " << arr[j] << ") ";
            count++;
            i++;
            j++;
        } else if (diff < k) {
            j++;
        } else {
            i++;
            if (i == j) j++;
        }
    }
    cout << "\nTotal number of pairs: " << count << endl;
    return 0;
}
