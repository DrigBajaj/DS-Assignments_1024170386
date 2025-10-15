#include <iostream>
using namespace std;
#define MAX 5
class CircularQueue {
    int front, rear;
    int arr[MAX];
	public:
    	CircularQueue() {
        	front = -1;
        	rear = -1;
    	}

    	bool isEmpty() {
        	return (front == -1);
    	}
    	bool isFull() {
        	return ((rear + 1) % MAX == front);
    	}
    	void enqueue(int val) {
        	if (isFull()) {
            	cout << "Queue is full. Cannot enqueue " << val << endl;
            	return;
        	}
        	if (isEmpty()) {
            	front = rear = 0;
        	} else {
            	rear = (rear + 1) % MAX;
        	}
        	arr[rear] = val;
        	cout << val << " enqueued to queue." << endl;
    	}
    	void dequeue() {
        	if (isEmpty()) {
	            cout << "Queue is empty. Cannot dequeue." << endl;
	            return;
	        }
	
	        cout << arr[front] << " dequeued from queue." << endl;
	
	        if (front == rear) {
	            // Queue becomes empty after dequeue
	            front = rear = -1;
	        } else {
	            front = (front + 1) % MAX;
	        }
	    }
	
	    void display() {
	        if (isEmpty()) {
	            cout << "Queue is empty." << endl;
	            return;
	        }
	
	        cout << "Queue elements: ";
	        int i = front;
	        while (true) {
	            cout << arr[i] << " ";
	            if (i == rear)
	                break;
	            i = (i + 1) % MAX;
	        }
	        cout << endl;
	    }
	
	    void peek() {
	        if (isEmpty()) {
	            cout << "Queue is empty." << endl;
	            return;
	        }
	        cout << "Front element is: " << arr[front] << endl;
	    }
};
int main() {
    CircularQueue q;
    int choice, val;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                if (q.isFull()) {
                    cout << "Queue is full. Cannot enqueue any more elements." << endl;
                } else {
                    cout << "Enter value to enqueue: ";
                    cin >> val;
                    q.enqueue(val);
                }
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << (q.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            case 4:
                cout << (q.isFull() ? "Queue is full." : "Queue is not full.") << endl;
                break;
            case 5:
                q.display();
                break;
            case 6:
                q.peek();
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 7);
    return 0;
}

