#include <iostream>
using namespace std;

int main(){
    int arr1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int i, j, arr2[3][2];
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            arr2[i][j] = arr1[j][i];
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            cout << arr2[i][j] << " ";
        }
        cout << "\n";
    }

}
