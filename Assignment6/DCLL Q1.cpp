#include <iostream>
using namespace std;
class DLLNode {
	public:
	    int data;
	    DLLNode* prev;
	    DLLNode* next;
	    DLLNode(int val) {
	        data = val;
	        prev = NULL;
	        next = NULL;
	    }
};
class CLLNode {
	public:
	    int data;
	    CLLNode* next;
	    CLLNode(int val) {
	        data = val;
	        next = NULL;
	    }
};
class DoublyLinkedList {
	private:
	    DLLNode* head;
	public:
	    DoublyLinkedList() {
	        head = NULL;
	    }
	    void insertAtBeginning(int val) {
	        DLLNode* newNode = new DLLNode(val);
	        if (head == NULL) {
	            head = newNode;
	            return;
	        }
	        newNode->next = head;
	        head->prev = newNode;
	        head = newNode;
	    }
	    void insertAtEnd(int val) {
	        DLLNode* newNode = new DLLNode(val);
	        if (head == NULL) {
	            head = newNode;
	            return;
	        }
	        DLLNode* temp = head;
	        while (temp->next != NULL) {
	            temp = temp->next;
	        }
	        temp->next = newNode;
	        newNode->prev = temp;
	    }
	    void insertAfter(int afterVal, int val) {
	        DLLNode* temp = head;
	        while (temp != NULL && temp->data != afterVal) {
	            temp = temp->next;
	        }
	        if (temp == NULL) {
	            cout << "Node " << afterVal << " not found.\n";
	            return;
	        }
	        DLLNode* newNode = new DLLNode(val);
	        newNode->next = temp->next;
	        newNode->prev = temp;
	        if (temp->next != NULL) {
	            temp->next->prev = newNode;
	        }
	        temp->next = newNode;
	    }
	    void insertBefore(int beforeVal, int val) {
	        if (head == NULL) {
	            cout << "List is empty.\n";
	            return;
	        }
	        if (head->data == beforeVal) {
	            insertAtBeginning(val);
	            return;
	        }
	        DLLNode* temp = head->next;
	        while (temp != NULL && temp->data != beforeVal) {
	            temp = temp->next;
	        }
	        if (temp == NULL) {
	            cout << "Node " << beforeVal << " not found.\n";
	            return;
	        }
	        DLLNode* newNode = new DLLNode(val);
	        newNode->next = temp;
	        newNode->prev = temp->prev;
	        temp->prev->next = newNode;
	        temp->prev = newNode;
	    }
	    void deleteNode(int val) {
	        if (head == NULL) {
	            cout << "List is empty.\n";
	            return;
	        }
	        DLLNode* temp = head;
	        while (temp != NULL && temp->data != val) {
	            temp = temp->next;
	        }
	        if (temp == NULL) {
	            cout << "Node " << val << " not found.\n";
	            return;
	        }
	        if (temp == head) {
	            head = head->next;
	            if (head != NULL) head->prev = NULL;
	            delete temp;
	            cout << "Node " << val << " deleted.\n";
	            return;
	        }
	        if (temp->next != NULL) {
	            temp->next->prev = temp->prev;
	        }
	        if (temp->prev != NULL) {
	            temp->prev->next = temp->next;
	        }
	        delete temp;
	        cout << "Node " << val << " deleted.\n";
	    }
	    bool search(int val) {
	        DLLNode* temp = head;
	        while (temp != NULL) {
	            if (temp->data == val) return true;
	            temp = temp->next;
	        }
	        return false;
	    }
	    void display() {
    		DLLNode* temp = head;
		    cout << "Doubly Linked List: ";
		    if (temp == NULL) {
		        cout << "List is empty.\n";
		        return;
		    }
		    while (temp->next != NULL) {
		        cout << temp->data << " <-> ";
		        temp = temp->next;
		    }
		    cout << temp->data << "\n";
		}
};
class CircularLinkedList {
	private:
	    CLLNode* tail;
	public:
	    CircularLinkedList() {
	        tail = NULL;
	    }
	    void insertAtBeginning(int val) {
	        CLLNode* newNode = new CLLNode(val);
	        if (tail == NULL) {
	            tail = newNode;
	            tail->next = tail;
	            return;
	        }
	        newNode->next = tail->next;
	        tail->next = newNode;
	    }
	    void insertAtEnd(int val) {
	        CLLNode* newNode = new CLLNode(val);
	        if (tail == NULL) {
	            tail = newNode;
	            tail->next = tail;
	            return;
	        }
	        newNode->next = tail->next;
	        tail->next = newNode;
	        tail = newNode;
	    }
	    void insertAfter(int afterVal, int val) {
	        if (tail == NULL) {
	            cout << "List is empty.\n";
	            return;
	        }
	        CLLNode* curr = tail->next;
	        do {
	            if (curr->data == afterVal) {
	                CLLNode* newNode = new CLLNode(val);
	                newNode->next = curr->next;
	                curr->next = newNode;
	                if (curr == tail) tail = newNode;
	                return;
	            }
	            curr = curr->next;
	        } while (curr != tail->next);
	        cout << "Node " << afterVal << " not found.\n";
	    }
	    void insertBefore(int beforeVal, int val) {
	        if (tail == NULL) {
	            cout << "List is empty.\n";
	            return;
	        }
	        CLLNode* curr = tail->next;
	        CLLNode* prev = tail;
	        do {
	            if (curr->data == beforeVal) {
	                CLLNode* newNode = new CLLNode(val);
	                newNode->next = curr;
	                prev->next = newNode;
	                if (curr == tail->next) tail->next = newNode;
	                return;
	            }
	            prev = curr;
	            curr = curr->next;
	        } while (curr != tail->next);
	        cout << "Node " << beforeVal << " not found.\n";
	    }
	    void deleteNode(int val) {
	        if (tail == NULL) {
	            cout << "List is empty.\n";
	            return;
	        }
	        CLLNode* curr = tail->next;
	        CLLNode* prev = tail;
	        do {
	            if (curr->data == val) {
	                if (curr == prev) {
	                    delete curr;
	                    tail = NULL;
	                } else {
	                    prev->next = curr->next;
	                    if (curr == tail) tail = prev;
	                    if (curr == tail->next) tail->next = curr->next;
	                    delete curr;
	                }
	                cout << "Node " << val << " deleted.\n";
	                return;
	            }
	            prev = curr;
	            curr = curr->next;
	        } while (curr != tail->next);
	        cout << "Node " << val << " not found.\n";
	    }
	    bool search(int val) {
	        if (tail == NULL) return false;
	        CLLNode* curr = tail->next;
	        do {
	            if (curr->data == val) return true;
	            curr = curr->next;
	        } while (curr != tail->next);
	        return false;
	    }
	    void display() {
	        if (tail == NULL) {
	            cout << "Circular Linked List is empty.\n";
	            return;
	        }
	        CLLNode* curr = tail->next;
	        cout << "Circular Linked List: ";
	        do {
	            cout << curr->data << " -> ";
	            curr = curr->next;
	        } while (curr != tail->next);
	        cout << "(back to head)\n";
	    }
};
void menu() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, listChoice, val, refVal;
    do {
        cout << "\nChoose Linked List type:\n1. Doubly Linked List\n2. Circular Linked List\n3. Exit\nChoice: ";
        cin >> listChoice;
        if (listChoice == 3) break;
        cout << "\nOperations:\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After a Node\n4. Insert Before a Node\n";
        cout << "5. Delete a Node\n6. Search for a Node\n7. Display List\n8. Back to Linked List Selection\nChoice: ";
        cin >> choice;
        switch (listChoice) {
            case 1:
                switch (choice) {
                    case 1:
                        cout << "Enter value to insert at beginning: ";
                        cin >> val;
                        dll.insertAtBeginning(val);
                        break;
                    case 2:
                        cout << "Enter value to insert at end: ";
                        cin >> val;
                        dll.insertAtEnd(val);
                        break;
                    case 3:
                        cout << "Insert after node with value: ";
                        cin >> refVal;
                        cout << "Enter value to insert: ";
                        cin >> val;
                        dll.insertAfter(refVal, val);
                        break;
                    case 4:
                        cout << "Insert before node with value: ";
                        cin >> refVal;
                        cout << "Enter value to insert: ";
                        cin >> val;
                        dll.insertBefore(refVal, val);
                        break;
                    case 5:
                        cout << "Enter value to delete: ";
                        cin >> val;
                        dll.deleteNode(val);
                        break;
                    case 6:
                        cout << "Enter value to search: ";
                        cin >> val;
                        if (dll.search(val)) cout << "Node found.\n";
                        else cout << "Node not found.\n";
                        break;
                    case 7:
                        dll.display();
                        break;
                    case 8:
                        break;
                    default:
                        cout << "Invalid choice.\n";
                }
                break;
            case 2:
                switch (choice) {
                    case 1:
                        cout << "Enter value to insert at beginning: ";
                        cin >> val;
                        cll.insertAtBeginning(val);
                        break;
                    case 2:
                        cout << "Enter value to insert at end: ";
                        cin >> val;
                        cll.insertAtEnd(val);
                        break;
                    case 3:
                        cout << "Insert after node with value: ";
                        cin >> refVal;
                        cout << "Enter value to insert: ";
                        cin >> val;
                        cll.insertAfter(refVal, val);
                        break;
                    case 4:
                        cout << "Insert before node with value: ";
                        cin >> refVal;
                        cout << "Enter value to insert: ";
                        cin >> val;
                        cll.insertBefore(refVal, val);
                        break;
                    case 5:
                        cout << "Enter value to delete: ";
                        cin >> val;
                        cll.deleteNode(val);
                        break;
                    case 6:
                        cout << "Enter value to search: ";
                        cin >> val;
                        if (cll.search(val)) cout << "Node found.\n";
                        else cout << "Node not found.\n";
                        break;
                    case 7:
                        cll.display();
                        break;
                    case 8:
                        break;
                    default:
                        cout << "Invalid choice.\n";
                }
                break;
            default:
                cout << "Invalid list type choice.\n";
        }
    } while (true);
}
int main() {
    menu();
    cout << "Program terminated.\n";
    return 0;
}
