#include <iostream>
using namespace std;

void binarySort(int a[], int n){
    for(int i=0; i<n-1; i++){
        bool swapped = false;
        for(int j=0; j<n-i-1; j++){
            if (a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                swapped = true;
            }
        }

        if(!swapped) {
            break;
        }
    }
}

int main(){
    int arr[] = {100, 90, 76, 89, 12};
    int size = sizeof(arr)/sizeof(arr[0]);
    binarySort(arr, size);
    cout << "sorted array: ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}