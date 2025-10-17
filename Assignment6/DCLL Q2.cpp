#include <iostream>
using namespace std;
class Node {
	public:
	    int data;
	    Node* next;
	    Node(int val) {
	        data = val;
	        next = NULL;
	    }
};
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
	}
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}
void displayCircularList(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl;
}
int main() {
    Node* head = NULL;
    insertAtEnd(head, 20);
    insertAtEnd(head, 100);
    insertAtEnd(head, 40);
    insertAtEnd(head, 80);
    insertAtEnd(head, 60);
    displayCircularList(head);
    return 0;
}
