#include <iostream>
using namespace std;
class SinglyLinkedList {
	private:
	    class Node {
	    public:
	        int data;
	        Node* next;
	        Node(int val, Node* nextNode = NULL) : data(val), next(nextNode) {}
	    };
	    Node* head;
	public:
	    SinglyLinkedList() : head(NULL) {}
	    void insertAtEnd(int value) {
	        Node* newNode = new Node(value);
	        if (head == NULL) {
	            head = newNode;
	            return;
	        }
	        Node* temp = head;
	        while (temp->next != NULL)
	            temp = temp->next;
	        temp->next = newNode;
	    }
	    void reverse() {
	        Node* prev = NULL;
	        Node* curr = head;
	        Node* next = NULL;
	        while (curr != NULL) {
	            next = curr->next;
	            curr->next = prev;
	            prev = curr;        
	            curr = next;
	        }
	        head = prev;
	    }
	    void display() {
	        if (head == NULL) {
	            cout << "List is empty.\n";
	            return;
	        }
	        Node* temp = head;
	        while (temp != NULL) {
	            cout << temp->data;
	            if (temp->next != NULL)
	                cout << " -> ";
	            temp = temp->next;
	        }
	        cout << "\n";
	    }
};
int main() {
    SinglyLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    cout << "Original Linked List: ";
    list.display();
    list.reverse();
    cout << "Reversed Linked List: ";
    list.display();
    return 0;
}
