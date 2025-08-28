#include <iostream>
using namespace std;
int main(){
    cout << "Diagonal matrix size?: ";
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cout << "Enter element "<<i+1 << ": ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Matrix: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (i == j){
                cout << arr[j];
            } else {
                cout << 0;
            }
            cout << " ";
        }

        cout << endl;
    }
}