#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    cout << "Enter string: ";
    string str;
    getline(cin, str);
    
    sort(str.begin(), str.end());

    cout <<"Sorted: ";
    cout << str << endl;
}