#include <iostream>
using namespace std;
int main() {
    int arr[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    for(int i=0; i<3; i++){
        int row_sum = 0;
        for(int j=0; j<2; j++){
            row_sum += arr[i][j];
        }
        cout << "Row " << i+1 << ": "<<row_sum << endl;
    }

    for(int i=0; i<2; i++){
        int col_sum = 0;
        for(int j=0; j<3; j++){
            col_sum += arr[j][i];
        }
        cout << "Col "<< i+1 << ": "<<col_sum << endl;
    }
}