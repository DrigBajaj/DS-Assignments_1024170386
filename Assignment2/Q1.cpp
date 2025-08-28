#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_Search(vector<int>& arr, int s){
    
    int low = 0;
    int high = arr.size()-1;

    while(low <= high){
        int mid = (low+high)/2;
        if (arr[mid] == s){
            return mid;
        } else if (arr[mid] > s){
            high = mid -1;
        } else {
            low = mid+1;
        }

    }
    return -1;
}

int main(){
    cout << "How many elements of array do you want?: ";
    int size;
    cin >> size;

    vector<int> a(size);
    for(int i=0; i<size; i++){
        cout << "Enter element "<<i+1<<": ";
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    cout << "Sorted: ";
    for(int i=0; i<size; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Enter value to search: ";
    int value;
    cin >> value;

    int c = binary_Search(a, value);
    if (c == -1) {
        cout << "Element not found";
    } else {
        cout << "Found at: " << c;
    }
}