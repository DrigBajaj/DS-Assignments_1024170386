#include <iostream>
using namespace std;
class DoublyNode {
	public:
	    int data;
	    DoublyNode* next;
	    DoublyNode* prev;
	
	    DoublyNode(int val) {
	        data = val;
	        next = NULL;
	        prev = NULL;
	    }
};
class Node {
	public:
	    int data;
	    Node* next;
	    Node(int val) {
	        data = val;
	        next = NULL;
    	}
};
void displayDoublyLinkedList(DoublyNode* head) {
    cout << "Doubly Linked List: ";
    DoublyNode* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int sizeOfDoublyLinkedList(DoublyNode* head) {
    int count = 0;
    DoublyNode* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
void displayCircularLinkedList(Node* head) {
    if (head == NULL) {
        cout << "Circular Linked List is empty." << endl;
        return;
    }
    cout << "Circular Linked List: ";
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl;
}
int sizeOfCircularLinkedList(Node* head) {
    if (head == NULL) return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}
int main() {
    DoublyNode* dHead = new DoublyNode(10);
    DoublyNode* dSecond = new DoublyNode(20);
    DoublyNode* dThird = new DoublyNode(30);
    dHead->next = dSecond;
    dSecond->prev = dHead;
    dSecond->next = dThird;
    dThird->prev = dSecond;
    displayDoublyLinkedList(dHead);
    cout << "Size of Doubly Linked List: " << sizeOfDoublyLinkedList(dHead) << endl;
    Node* cHead = new Node(5);
    Node* cSecond = new Node(15);
    Node* cThird = new Node(25);
    Node* cFourth = new Node(35);
	cHead->next = cSecond;
    cSecond->next = cThird;
    cThird->next = cFourth;
    cFourth->next = cHead;
    displayCircularLinkedList(cHead);
    cout << "Size of Circular Linked List: " << sizeOfCircularLinkedList(cHead) << endl;
    return 0;
}
