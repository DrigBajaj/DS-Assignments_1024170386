#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = 6;
    int missing = -1;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] != i + 1) {
            missing = i + 1;
            break;
        }
    }
    if (missing == -1) {
        missing = n;
    }
    cout << "Missing number is: " << missing << endl;
    return 0;
}
