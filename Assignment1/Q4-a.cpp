#include <iostream>
using namespace std;

int *reverse(int X[], int s){
    for (int i=0; i<s/2; i++){
        int temp = X[i];
        X[i] = X[s-i-1];
        X[s-1-i] = temp;
    }

    return X;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int *B = reverse(arr, size);
    for(int i=0; i<size; i++){
        cout << B[i] << " ";
    }
}
