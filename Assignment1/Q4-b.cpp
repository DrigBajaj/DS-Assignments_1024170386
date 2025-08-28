#include <iostream>
using namespace std;

int main(){
   int arr1[2][3] = {{1, 2, 3}, {4, 5, 6}}, arr2[3][2] = {{1, 2}, {3, 4}, {5, 6}};
   int arr2_transpose[2][3], i, j;
   for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            arr2_transpose[i][j] = arr2[j][i];
        }
    } 

    // 1 2 3      1 3 5
    // 4 5 6      2 4 6

    int final[2][2];
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            final[i][j] = 0;
            for(int k=0; k<3; k++){
                final[i][j] += arr1[i][k]*arr2_transpose[j][k];
            }
        }
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout << final[i][j] << " ";
        }
        cout << "\n";
    }
}