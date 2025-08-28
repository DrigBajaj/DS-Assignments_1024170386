#include <iostream>
using namespace std;

int remove_duplicates(int X[], int size){
    if (X == nullptr){
        return 0;
    } 
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size-1;){
            if (X[i] == X[j]){
                for(int k=j; k<size; k++){ 
                    X[k]=X[k+1];
                }
                size--;
            } else {
                j++;
            }
        }
    }

    return size;

}

int main() {
    int arr[] = {1, 2, 2, 3, 3, 4};
    int s = sizeof(arr)/sizeof(arr[0]);
    int B = remove_duplicates(arr, s);
    for(int i=0; i<B; i++){
        cout << arr[i] << " ";
    }
}