#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = 6;
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Input array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int missing = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] != i + 1) {
            missing = i + 1;
            break;
        }
    }
    if (missing == -1) {
        missing = n;
    }
    cout << "Missing number (linear search): " << missing << endl;
    return 0;
}
