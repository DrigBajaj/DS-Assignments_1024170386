#include <iostream>
using namespace std;
int main(){
    cout << "Enter number of array elements: ";
    int num;
    cin >> num;
    int a[num];
    for(int i=0; i<num; i++){
        cout << "Enter element "<<i+1 <<": ";
        cin >> a[i];
    }
    int count = 0;
    cout << "---------------\nInversion pairs\n";
    for(int i=0; i<num; i++){
        for(int j=i+1; j<num; j++){
            if (a[i] > a[j]){
                count++;
                cout << "(" << a[i] << " , " << a[j] << ")"<<endl;
            }
        }
    }

    cout << "Number of inversion: "<<count;
}