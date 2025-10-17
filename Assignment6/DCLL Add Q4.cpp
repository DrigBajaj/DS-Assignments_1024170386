#include <iostream>
using namespace std;
class Node {
	public:
	    int data;
	    Node* next;
	    Node* prev;
	    Node* random;
	    Node(int val) {
	        data = val;
	        next = NULL;
	        prev = NULL;
	        random = NULL;
	    }
};
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
int getLength(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}
Node* getNodeAt(Node* head, int index) {
    int i = 0;
    while (head && i < index) {
        head = head->next;
        i++;
    }
    return head;
}
void setCorrectRandoms(Node* head) {
    int len = getLength(head);
    for (int i = 0; i < len; i++) {
        Node* curr = getNodeAt(head, i);
        Node* target = getNodeAt(head, len - 1 - i);
        curr->random = target;
    }
}
void correctWrongRandom(Node* head) {
    int len = getLength(head);
    for (int i = 0; i < len; i++) {
        Node* curr = getNodeAt(head, i);
        Node* expected = getNodeAt(head, len - 1 - i);
        if (curr->random != expected) {
            curr->random = expected;
        }
    }
}
void displayWithRandoms(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << ":";
        if (temp->random != NULL)
            cout << temp->random->data;
        else
            cout << "NULL";
        cout << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    Node* head = NULL;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    setCorrectRandoms(head);
    head->next->random = head;
    cout << "Before correction:" << endl;
    displayWithRandoms(head);
    correctWrongRandom(head);
    cout << "After correction:" << endl;
    displayWithRandoms(head);
    return 0;
}
