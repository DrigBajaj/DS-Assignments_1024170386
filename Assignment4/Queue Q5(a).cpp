#include <iostream>
#include <queue>
using namespace std;
class StackTwoQueues {
    queue<int> q1, q2;
	public:
	    void push(int x) {
	        q1.push(x);
	    }
	    int pop() {
	        if (q1.empty()) {
	            cout << "Stack is empty\n";
	            return -1;
	        }
	        while (q1.size() > 1) {
	            q2.push(q1.front());
	            q1.pop();
	        }
	        int top = q1.front();
	        q1.pop();
	        swap(q1, q2);
	        return top;
	    }
	    int top() {
	        if (q1.empty()) {
	            cout << "Stack is empty\n";
	            return -1;
	        }
	        while (q1.size() > 1) {
	            q2.push(q1.front());
	            q1.pop();
	        }
	        int top = q1.front();
	        q2.push(top);
	        q1.pop();
	        swap(q1, q2);
	        return top;
	    }
	    bool empty() {
	        return q1.empty();
	    }
};
int main() {
    StackTwoQueues s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.top() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    s.push(40);
    cout << "Top element: " << s.top() << endl;
    return 0;
}

