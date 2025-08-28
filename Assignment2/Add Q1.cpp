#include <iostream>
using namespace std;
int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;
    int matrix[100][100];
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> matrix[i][j];
    bool found = false;
    for (int i = 0; i < rows; ++i) {
        int minCol = 0;
        for (int j = 1; j < cols; ++j) {
            if (matrix[i][j] < matrix[i][minCol]) {
                minCol = j;
            }
        }
        int candidate = matrix[i][minCol];
        bool isSaddle = true;
        for (int k = 0; k < rows; ++k) {
            if (matrix[k][minCol] > candidate) {
                isSaddle = false;
                break;
            }
        }
        if (isSaddle) {
            cout << "Saddle point found at (" << i << ", " << minCol << ") with value: " << candidate << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No saddle point found in the matrix." << endl;
    return 0;
}
