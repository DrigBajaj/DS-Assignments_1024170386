#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> dailyTemperatures(const vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
            int idx = s.top();
            s.pop();
            answer[idx] = i - idx;
        }
        s.push(i);
    }
    return answer;
}
int main() {
    vector<int> temperatures;
    temperatures.push_back(73);
    temperatures.push_back(74);
    temperatures.push_back(75);
    temperatures.push_back(71);
    temperatures.push_back(69);
    temperatures.push_back(72);
    temperatures.push_back(76);
    temperatures.push_back(73);
    vector<int> res = dailyTemperatures(temperatures);
    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

