#include <iostream>
using namespace std;
int main(){
    cout << "Enter a character: ";
    char c;
    cin >> c;
    //c = tolower(c); OR
    c = c+32;
    cout << "Lowercase: "<<c<<endl;
}