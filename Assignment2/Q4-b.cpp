#include <iostream>
using namespace std;
int main(){
    cout << "Enter string: ";
    string string;
    getline(cin, string);
    for(int i=0; i<(string.length())/2; i++){
        char temp = string[i];
        string[i] = string[string.length()-i-1];
        string[string.length()-i-1] = temp;
    }

    cout << string;
    
}