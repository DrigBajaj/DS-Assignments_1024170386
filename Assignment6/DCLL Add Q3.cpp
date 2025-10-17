#include <iostream>
using namespace std;
class Node {
	public:
	    int data;
	    Node* next;
	    Node* prev;
	
	    Node(int val) {
	        data = val;
	        next = NULL;
	        prev = NULL;
	    }
};
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
void displayList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << " <-> ";
        head = head->next;
    }
    cout << " <-> NULL" << endl;
}
Node* reverseInGroups(Node* head, int k) {
    if (head == NULL || k <= 1)
        return head;

    Node* curr = head;
    Node* newHead = NULL;
    Node* prevGroupEnd = NULL;
    while (curr != NULL) {
        Node* groupStart = curr;
        Node* temp = curr;
        int count = 0;
        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }
        Node* prev = temp;
        Node* node = curr;
        for (int i = 0; i < count; i++) {
            Node* nextNode = node->next;
            node->next = prev;
            if (prev != NULL) prev->prev = node;
            prev = node;
            node = nextNode;
        }
        if (prevGroupEnd == NULL)
            newHead = prev;
        else {
            prevGroupEnd->next = prev;
            prev->prev = prevGroupEnd;
        }
        prevGroupEnd = groupStart;
        curr = temp;
    }
    return newHead;
}
int main() {
    Node* head = NULL;
    int n, k;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertAtEnd(head, val);
    }
    cout << "Enter group size k: ";
    cin >> k;
    cout << "\nOriginal Doubly Linked List:\n";
    displayList(head);
    head = reverseInGroups(head, k);
    cout << "\nDoubly Linked List after reversing in groups of " << k << ":\n";
    displayList(head);
    return 0;
}
