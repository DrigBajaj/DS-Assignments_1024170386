#include <iostream>
using namespace std;
class PriorityQueue {
	private:
	    int* heap;
	    int capacity;
	    int size;
	    void swap(int &a, int &b) {
	        int temp = a;
	        a = b;
	        b = temp;
	    }
	    void heapifyUp(int index) {
	        int parent = (index - 1) / 2;
	        while (index > 0 && heap[parent] < heap[index]) {
	            swap(heap[parent], heap[index]);
	            index = parent;
	            parent = (index - 1) / 2;
	        }
	    }
	    void heapifyDown(int index) {
	        int largest = index;
	        int left = 2 * index + 1;
	        int right = 2 * index + 2;
	        if (left < size && heap[left] > heap[largest])
	            largest = left;
	        if (right < size && heap[right] > heap[largest])
	            largest = right;
	        if (largest != index) {
	            swap(heap[index], heap[largest]);
	            heapifyDown(largest);
	        }
	    }
	public:
	    PriorityQueue(int cap) {
	        capacity = cap;
	        heap = new int[capacity];
	        size = 0;
	    }
	    void insert(int value) {
	        if (size == capacity) {
	            cout << "Priority Queue is full!" << endl;
	            return;
	        }
	        heap[size] = value;
	        heapifyUp(size);
	        size++;
	    }
	    int extractMax() {
	        if (size == 0) {
	            cout << "Priority Queue is empty!" << endl;
	            return -1;
	        }
	        int maxVal = heap[0];
	        heap[0] = heap[size - 1];
	        size--;
	        heapifyDown(0);
	        return maxVal;
	    }
	    int peek() {
	        if (size == 0) {
	            cout << "Priority Queue is empty!" << endl;
	            return -1;
	        }
	        return heap[0];
	    }
	    void display() {
	        for (int i = 0; i < size; i++)
	            cout << heap[i] << " ";
	        cout << endl;
	    }
};
int main() {
    PriorityQueue pq(10);
    pq.insert(20);
    pq.insert(15);
    pq.insert(30);
    pq.insert(40);
    pq.insert(10);
    cout << "Priority Queue (Heap): ";
    pq.display();
    cout << "Maximum element: " << pq.peek() << endl;
    cout << "Extract max: " << pq.extractMax() << endl;
    cout << "Priority Queue after extraction: ";
    pq.display();
    pq.insert(50);
    cout << "Priority Queue after inserting 50: ";
    pq.display();
    return 0;
}
