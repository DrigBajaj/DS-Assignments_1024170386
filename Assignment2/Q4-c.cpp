#include <iostream>
using namespace std;
#include <string>

bool isVowel(char ch){
    ch = tolower(ch);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        return 1;
    }
}

string removeVowel(string str){
    string res = "";
    for(char ch : str){
        if (!isVowel(ch)){
            res += ch;
        }
    }

    return res;
}

int main(){
    cout << "Enter string: ";
    string input;
    getline(cin, input);
    string noVowels = removeVowel(input);
    cout << "With no vowels: "<<noVowels;
}