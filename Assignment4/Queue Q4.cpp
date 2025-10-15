#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<char> q;
    int freq[256] = {0};
    string input;
    cout << "Enter characters separated by spaces:" << endl;
    getline(cin, input);
    size_t pos = 0;
    while (pos < input.size()) {
        while (pos < input.size() && input[pos] == ' ') pos++;
        if (pos >= input.size()) break;
        char ch = input[pos];
        pos++;
        freq[(unsigned char)ch]++;
        q.push(ch);
        while (!q.empty() && freq[(unsigned char)q.front()] > 1) {
            q.pop();
        }
        if (!q.empty())
            cout << q.front() << " ";
        else
            cout << -1 << " ";
    }
    cout << endl;
    return 0;
}

