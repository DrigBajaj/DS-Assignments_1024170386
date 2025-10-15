#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int countStudentsUnableToEat(const vector<int>& students, const vector<int>& sandwiches) {
    queue<int> q;
    for (size_t i = 0; i < students.size(); i++) 
	{
    q.push(students[i]);
	}
    int index = 0;
    int countRejected = 0;
    while (!q.empty() && countRejected < q.size()) {
        if (q.front() == sandwiches[index]) {
            q.pop();
            index++;
            countRejected = 0;
        } else {
            int frontStudent = q.front();
            q.pop();
            q.push(frontStudent);
            countRejected++;
        }
    }
    return q.size();
}
int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    vector<int> students(n), sandwiches(n);
    cout << "Enter preferences of students (0 for circular, 1 for square):\n";
    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }
    cout << "Enter sandwiches stack (top to bottom) preferences (0 for circular, 1 for square):\n";
    for (int i = 0; i < n; i++) {
        cin >> sandwiches[i];
    }
    int result = countStudentsUnableToEat(students, sandwiches);
    cout << "Number of students unable to eat: " << result << endl;
    return 0;
}

