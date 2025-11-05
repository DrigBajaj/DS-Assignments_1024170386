#include <iostream>
using namespace std;
int findMissing(int arr[], int low, int high) {
    if (low > high)
        return high + 2;
    int mid = (low + high) / 2;
    if (arr[mid] != mid + 1) {
        if (mid == 0 || arr[mid - 1] == mid)
            return mid + 1;
        else
            return findMissing(arr, low, mid - 1);
    } else {
        return findMissing(arr, mid + 1, high);
    }
}
int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = 6;
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Input array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    int missing = findMissing(arr, 0, size - 1);
    cout << "Missing number (binary search): " << missing << endl;
    return 0;
}
