#include <iostream>
using namespace std;
class Node {
	public:
	    int data;
	    Node* next;
	    Node(int val) : data(val), next(NULL) {}
};
class LinkedList {
	public:
	    Node* head;
	    LinkedList() : head(NULL) {}
	    void insertAtEnd(int val) {
	        Node* newNode = new Node(val);
	        if (head == NULL) {
	            head = newNode;
	            return;
	        }
	        Node* temp = head;
	        while (temp->next != NULL)
	            temp = temp->next;
	        temp->next = newNode;
	    }
	    void createLoop(int pos) {
	        if (pos <= 0) return;
	        Node* loopNode = head;
	        int count = 1;
	        while (count < pos && loopNode != NULL) {
	            loopNode = loopNode->next;
	            count++;
	        }
	        if (loopNode == NULL) return;
	        Node* tail = head;
	        while (tail->next != NULL) {
	            tail = tail->next;
	        }
	        tail->next = loopNode;
	    }
	    void detectAndRemoveLoop() {
	        if (head == NULL || head->next == NULL)
	            return;
	        Node* slow = head;
	        Node* fast = head;
	        while (fast != NULL && fast->next != NULL) {
	            slow = slow->next;
	            fast = fast->next->next;
	            if (slow == fast) {
	                removeLoop(slow);
	                cout << "Loop removed from the linked list.\n";
	                return;
	            }
	        }
	        cout << "No loop detected.\n";
	    }
	private:
	    void removeLoop(Node* loopNode) {
	        Node* ptr1 = head;
	        Node* ptr2 = loopNode;
	        while (ptr1 != ptr2) {
	            ptr1 = ptr1->next;
	            ptr2 = ptr2->next;
	        }
	        Node* prev = ptr2;
	        while (prev->next != ptr2) {
	            prev = prev->next;
	        }
	        prev->next = NULL;
	    }
	public:
	    void display() {
	        Node* temp = head;
	        while (temp != NULL) {
	            cout << temp->data;
	            if (temp->next != NULL) cout << " -> ";
	            temp = temp->next;
	        }
	        cout << "\n";
	    }
};
int main() {
    LinkedList list;
    for (int i = 1; i <= 5; i++)
        list.insertAtEnd(i);
    list.createLoop(3);
    list.detectAndRemoveLoop();
    cout << "Linked list after loop removal: ";
    list.display();
    return 0;
}

