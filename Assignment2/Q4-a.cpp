#include <iostream>
using namespace std;

int main(){
    cout <<"Enter word1: ";
    string word1, word2;
    getline(cin, word1);
    cout << "Enter word2: ";
    getline(cin, word2);
    word1+= " " +word2;
    cout << word1;
}