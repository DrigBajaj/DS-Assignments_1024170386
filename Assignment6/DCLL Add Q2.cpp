#include <iostream>
using namespace std;
class DNode {
	public:
	    int data;
	    DNode* next;
	    DNode* prev;
	
	    DNode(int val) {
	        data = val;
	        next = NULL;
	        prev = NULL;
	    }
};
class CNode {
	public:
	    int data;
	    CNode* next;
	
	    CNode(int val) {
	        data = val;
	        next = NULL;
	    }
};
int countOnes(int n) {
    int count = 0;
    while (n > 0) {
        if (n & 1)
            count++;
        n >>= 1;
    }
    return count;
}
void removeEvenParityFromDLL(DNode*& head) {
    DNode* curr = head;
    while (curr != NULL) {
        int ones = countOnes(curr->data);
        if (ones % 2 == 0) {
            DNode* toDelete = curr;
            if (curr->prev)
                curr->prev->next = curr->next;
            else
                head = curr->next;
            if (curr->next)
                curr->next->prev = curr->prev;
            curr = curr->next;
            delete toDelete;
        } else {
            curr = curr->next;
        }
    }
}
void removeEvenParityFromCLL(CNode*& head) {
    if (head == NULL)
        return;
    while (head && countOnes(head->data) % 2 == 0) {
        CNode* temp = head;
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        } else {
            CNode* tail = head;
            while (tail->next != head)
                tail = tail->next;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }
    if (!head) return;
    CNode* curr = head;
    while (curr->next != head) {
        if (countOnes(curr->next->data) % 2 == 0) {
            CNode* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
}
void displayDLL(DNode* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL)
            cout << " <=> ";
        head = head->next;
    }
    cout << endl;
}
void displayCLL(CNode* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    CNode* temp = head;
    do {
        cout << temp->data;
        temp = temp->next;
        if (temp != head)
            cout << " -> ";
    } while (temp != head);
    cout << endl;
}
int main() {
    DNode* dhead = new DNode(18);
    dhead->next = new DNode(15);
    dhead->next->prev = dhead;
    dhead->next->next = new DNode(8);
    dhead->next->next->prev = dhead->next;
    dhead->next->next->next = new DNode(9);
    dhead->next->next->next->prev = dhead->next->next;
    dhead->next->next->next->next = new DNode(14);
    dhead->next->next->next->next->prev = dhead->next->next->next;
    cout << "Original DLL: ";
    displayDLL(dhead);
    removeEvenParityFromDLL(dhead);
    cout << "DLL after removing even parity nodes: ";
    displayDLL(dhead);
    cout << endl;
    CNode* chead = new CNode(9);
    chead->next = new CNode(11);
    chead->next->next = new CNode(34);
    chead->next->next->next = new CNode(6);
    chead->next->next->next->next = new CNode(13);
    chead->next->next->next->next->next = new CNode(21);
    chead->next->next->next->next->next->next = chead;
    cout << "Original CLL: ";
    displayCLL(chead);
    removeEvenParityFromCLL(chead);
    cout << "CLL after removing even parity nodes: ";
    displayCLL(chead);
    return 0;
}
