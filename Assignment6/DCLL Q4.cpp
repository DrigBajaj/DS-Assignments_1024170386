#include <iostream>
using namespace std;
class DoublyNode {
	public:
	    char data;
	    DoublyNode* next;
	    DoublyNode* prev;
	
	    DoublyNode(char val) {
	        data = val;
	        next = NULL;
	        prev = NULL;
	    }
};
void insertAtEnd(DoublyNode*& head, char val) {
    DoublyNode* newNode = new DoublyNode(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    DoublyNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
bool isPalindrome(DoublyNode* head) {
    if (head == NULL) return true;
    DoublyNode* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    while (head != tail && head->prev != tail) {
        if (head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}
int main() {
    DoublyNode* head = NULL;
    string input;
    cout << "Enter characters for the doubly linked list (no spaces): ";
    cin >> input;
    for (int i = 0; i < (int)input.length(); i++) {
        insertAtEnd(head, input[i]);
    }
    if (isPalindrome(head))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}
