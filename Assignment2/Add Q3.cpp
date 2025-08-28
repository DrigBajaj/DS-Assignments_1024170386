#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter n for an n x n spiral matrix: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid size\n";
        return 0;
    }
    int matrix[100][100];
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; ++j)
            matrix[top][j] = num++;
        top++;
        for (int i = top; i <= bottom; ++i)
            matrix[i][right] = num++;
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; --j)
                matrix[bottom][j] = num++;
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i)
                matrix[i][left] = num++;
            left++;
        }
    }
    cout << "Spiral matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
