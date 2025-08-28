#include <iostream>
#include <algorithm>
using namespace std;

int missingNumber(int a[], int s){
    int expected = 0, actual = 0;
    for(int i=0; i<s; i++){
        actual += a[i];
    }
    for(int i=0; i<=a[s-1]; i++){
        expected += i;
    }

    return (expected-actual);
}

int main(){
    int arr[] = {0, 5, 3, 1, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+size);
    int ans = missingNumber(arr, size);
    cout << "Missing number: "<<ans;

}