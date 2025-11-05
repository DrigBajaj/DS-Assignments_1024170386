#include <iostream>
#include <string>
using namespace std;
int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string str1, str2;
        cout << "\nTest case " << t << ":\n";
        cout << "Enter first string: ";
        cin >> str1;
        cout << "Enter second string: ";
        cin >> str2;
        if (str1.length() != str2.length()) {
            cout << "Result: No, the strings are NOT anagrams.\n";
            continue;
        }
        int freq1[26] = {0};
        int freq2[26] = {0};
        int n = str1.length();
        for (int i = 0; i < n; i++) {
            freq1[str1[i] - 'a']++;
            freq2[str2[i] - 'a']++;
        }
        bool isAnagram = true;
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                isAnagram = false;
                break;
            }
        }
        if (isAnagram) {
            cout << "Result: Yes, the strings are anagrams.\n";
        } else {
            cout << "Result: No, the strings are NOT anagrams.\n";
        }
    }
    return 0;
}
