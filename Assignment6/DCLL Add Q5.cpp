#include <iostream>
#include <vector>
using namespace std;
class Node {
	public:
	    int data;
	    Node* next;
	    Node* prev;
	    Node* up;
	    Node* down;
	    Node(int val) {
	        data = val;
	        next = prev = up = down = NULL;
	    }
};
class DoublyLinkedMatrix {
    vector<vector<Node*> > nodes;
    int M, N;
	public:
	    DoublyLinkedMatrix(int rows, int cols, int matrix[][3]) {
	        M = rows;
	        N = cols;
	        nodes.resize(M, vector<Node*>(N, NULL));
	        for (int i = 0; i < M; i++) {
	            for (int j = 0; j < N; j++) {
	                nodes[i][j] = new Node(matrix[i][j]);
	            }
	        }
	        for (int i = 0; i < M; i++) {
	            for (int j = 0; j < N; j++) {
	                nodes[i][j]->next = (j + 1 < N) ? nodes[i][j + 1] : NULL;
	                nodes[i][j]->prev = (j - 1 >= 0) ? nodes[i][j - 1] : NULL;
	                nodes[i][j]->up = (i - 1 >= 0) ? nodes[i - 1][j] : NULL;
	                nodes[i][j]->down = (i + 1 < M) ? nodes[i + 1][j] : NULL;
	            }
	        }
	    }
	    void print() {
	        for (int i = 0; i < M; i++) {
	            for (int j = 0; j < N; j++) {
	                Node* curr = nodes[i][j];
	                cout << curr->data << "(";
	                if (curr->next != NULL) cout << curr->next->data; else cout << "NULL";
	                cout << ",";
	                if (curr->prev != NULL) cout << curr->prev->data; else cout << "NULL";
	                cout << ",";
	                if (curr->up != NULL) cout << curr->up->data; else cout << "NULL";
	                cout << ",";
	                if (curr->down != NULL) cout << curr->down->data; else cout << "NULL";
	                cout << ") ";
	            }
	            cout << "\n";
	        }
	    }
	    ~DoublyLinkedMatrix() {
	        for (int i = 0; i < M; i++) {
	            for (int j = 0; j < N; j++) {
	                delete nodes[i][j];
	            }
	        }
	    }
};
int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    DoublyLinkedMatrix dlm(3, 3, matrix);
    dlm.print();
    return 0;
}
