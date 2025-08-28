#include <iostream>
using namespace std;
int main(){
    cout << "Enter number of elements to be stored: ";
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cout << "Enter value of element "<<i+1<<": ";
        cin >> a[i];
    }
    int count = 0;
    for(int i=0 ; i<n; i++){
        bool distinct = true;
        for(int j=0; j<i; j++){
            if (a[i] == a[j]){
                distinct = false;
                break;
            }
        }

        if(distinct){
            cout << a[i] << " ";
            count++;
        }
    }
    cout << "\nNo. of distinct elements: "<<count;

}