#include <iostream>
using namespace std;
int main() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;
    int matrix[100][100];
    cout << "Enter matrix elements:\n";
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            cin >> matrix[i][j];
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    cout << "Spiral order:\n";
    while(top <= bottom && left <= right){
        for(int i = left; i <= right; i++)
            cout << matrix[top][i] << " ";
        top++;
        for(int i = top; i <= bottom; i++)
            cout << matrix[i][right] << " ";
        right--;
        if(top <= bottom) {
            for(int i = right; i >= left; i--)
                cout << matrix[bottom][i] << " ";
            bottom--;
        }
        if(left <= right) {
            for(int i = bottom; i >= top; i--)
                cout << matrix[i][left] << " ";
            left++;
        }
    }
    cout << endl;
    return 0;
}
