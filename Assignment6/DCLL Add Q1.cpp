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
void splitCircularList(Node* head, Node*& head1, Node*& head2) {
    if (head == NULL || head->next == head) {
        head1 = head;
        head2 = NULL;
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast->next->next == head)
        fast = fast->next;
    head1 = head;
    head2 = slow->next;
    slow->next = head1;
    fast->next = head2;
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
    cout << endl;
}
int main() {
    Node* head = NULL;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertAtEnd(head, val);
    }
    Node* head1 = NULL;
    Node* head2 = NULL;
    splitCircularList(head, head1, head2);
    cout << "\nFirst half: ";
    displayCircularList(head1);
    cout << "Second half: ";
    displayCircularList(head2);
    return 0;
}
