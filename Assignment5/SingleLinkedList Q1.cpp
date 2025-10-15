#include <iostream>
using namespace std;
class SinglyLinkedList {
	private:
	    class Node {
	    public:
	        int data;
	        Node* next;
	        Node(int val,Node* nextNode=NULL) : data(val), next(nextNode) {}
	    };
	    Node* head;
	public:
	    SinglyLinkedList() {
	        head = NULL;
	    }
	    void insertAtBeginning(int value) {
	        Node* newNode = new Node{value, head};
	        head = newNode;
	        cout << "Inserted " << value << " at the beginning.\n";
	    }
	    void insertAtEnd(int value) {
	        Node* newNode = new Node{value, NULL};
	        if (head == NULL) {
	            head = newNode;
	        } else {
	            Node* temp = head;
	            while (temp->next != NULL) temp = temp->next;
	            temp->next = newNode;
	        }
	        cout << "Inserted " << value << " at the end.\n";
	    }
	    void insertBeforeAfter(int valueToInsert, int targetValue, bool before) {
	        if (head == NULL) {
	            cout << "List is empty. Cannot insert.\n";
	            return;
	        }
	        if (before) {
	            if (head->data == targetValue) {
	                insertAtBeginning(valueToInsert);
	                return;
	            }
	            Node* prev = NULL;
	            Node* curr = head;
	            while (curr != NULL && curr->data != targetValue) {
	                prev = curr;
	                curr = curr->next;
	            }
	            if (curr == NULL) {
	                cout << "Node " << targetValue << " not found.\n";
	                return;
	            }
	            Node* newNode = new Node{valueToInsert, curr};
	            if (prev) prev->next = newNode;
	            cout << "Inserted " << valueToInsert << " before node " << targetValue << ".\n";
	        } else {
	            Node* curr = head;
	            while (curr != NULL && curr->data != targetValue) {
	                curr = curr->next;
	            }
	            if (curr == NULL) {
	                cout << "Node " << targetValue << " not found.\n";
	                return;
	            }
	            Node* newNode = new Node{valueToInsert, curr->next};
	            curr->next = newNode;
	            cout << "Inserted " << valueToInsert << " after node " << targetValue << ".\n";
	        }
	    }
	    void deleteFromBeginning() {
	        if (head == NULL) {
	            cout << "List is empty. Nothing to delete.\n";
	            return;
	        }
	        Node* temp = head;
	        head = head->next;
	        cout << "Deleted node with value " << temp->data << " from beginning.\n";
	        delete temp;
	    }
	    void deleteFromEnd() {
	        if (head == NULL) {
	            cout << "List is empty. Nothing to delete.\n";
	            return;
	        }
	        if (head->next == NULL) {
	            cout << "Deleted node with value " << head->data << " from end.\n";
	            delete head;
	            head = NULL;
	            return;
	        }
	        Node* temp = head;
	        Node* prev = NULL;
	        while (temp->next != NULL) {
	            prev = temp;
	            temp = temp->next;
	        }
	        prev->next = NULL;
	        cout << "Deleted node with value " << temp->data << " from end.\n";
	        delete temp;
	    }
	    void deleteNode(int value) {
	        if (head == NULL) {
	            cout << "List is empty. Nothing to delete.\n";
	            return;
	        }
	        if (head->data == value) {
	            deleteFromBeginning();
	            return;
	        }
	        Node* temp = head;
	        Node* prev = NULL;
	        while (temp != NULL && temp->data != value) {
	            prev = temp;
	            temp = temp->next;
	        }
	        if (temp == NULL) {
	            cout << "Node with value " << value << " not found.\n";
	            return;
	        }
	        prev->next = temp->next;
	        cout << "Deleted node with value " << value << ".\n";
	        delete temp;
	    }
	    void searchNode(int value) {
	        Node* temp = head;
	        int position = 1;
	        while (temp != NULL) {
	            if (temp->data == value) {
	                cout << "Node with value " << value << " found at position " << position << ".\n";
	                return;
	            }
	            temp = temp->next;
	            position++;
	        }
	        cout << "Node with value " << value << " not found.\n";
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
    int choice, val, target;
    bool before;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before/after a node\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete a specific node\n";
        cout << "7. Search for a node\n";
        cout << "8. Display list\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Insert before or after target? (b/a): ";
                char ch;
                cin >> ch;
                before = (ch == 'b' || ch == 'B');
                list.insertBeforeAfter(val, target, before);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter value of node to delete: ";
                cin >> val;
                list.deleteNode(val);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> val;
                list.searchNode(val);
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
