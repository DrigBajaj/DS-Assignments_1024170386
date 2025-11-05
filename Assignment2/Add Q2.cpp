#include <iostream>
#include <string>
using namespace std;
int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string s;
        cout << "\nTest case " << t << ":\n";
        cout << "Enter the string: ";
        cin >> s;
        int freq[26] = {0};
        int n = s.length();
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        bool possible = false;
        for (int i = 0; i < 26; i++) {
            if (freq[i] >= 3) {
                possible = true;
                break;
            }
        }
        if (possible) {
            cout << "Result: Yes, the string can be split into three parts as required.\n";
        } else {
            cout << "Result: No, the string cannot be split into three parts as required.\n";
        }
    }
    return 0;
}
