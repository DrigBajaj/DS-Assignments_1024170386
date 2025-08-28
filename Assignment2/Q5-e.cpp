#include <iostream>
using namespace std;
int main(){
    cout << "Size of matrix?: ";
    int size;
    cin >> size;
    int n = size*(size+1)/2;
    int a[n];
    for(int i=0; i<n; i++){
        cout << "Enter element "<<i+1 << ": ";
        cin >> a[i];
    }

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if (i >= j){
                cout << a[i*(i+1)/2 + j] << " ";
            } else {
                cout << a[j*(j+1)/2 + i] << " ";
            }
        }
    
        cout << endl;
    }
    
}