#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;
class Node {
	public:
	    int val;
	    Node* left;
	    Node* right;
	    Node(int value) {
	        val = value;
	        left = NULL;
	        right = NULL;
	    }
};
vector<Node*> generateTreesHelper(int start, int end) {
    vector<Node*> allTrees;
    if (start > end) {
        allTrees.push_back(NULL);
        return allTrees;
    }
    for (int i = start; i <= end; i++) {
        vector<Node*> leftTrees = generateTreesHelper(start, i - 1);
        vector<Node*> rightTrees = generateTreesHelper(i + 1, end);
        for (int l = 0; l < leftTrees.size(); l++) {
            for (int r = 0; r < rightTrees.size(); r++) {
                Node* root = new Node(i);
                root->left = leftTrees[l];
                root->right = rightTrees[r];
                allTrees.push_back(root);
            }
        }
    }
    return allTrees;
}
vector<Node*> generateTrees(int n) {
    if (n == 0) return vector<Node*>();
    return generateTreesHelper(1, n);
}
void printLevelOrder(Node* root) {
    if (root == NULL) {
        cout << "[]";
        return;
    }
    queue<Node*> q;
    q.push(root);
    vector<string> result;
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if (curr != NULL) {
            stringstream ss;
            ss << curr->val;
            result.push_back(ss.str());
            q.push(curr->left);
            q.push(curr->right);
        } else {
            result.push_back("null");
        }
    }
    while (!result.empty() && result[result.size() - 1] == "null")
        result.pop_back();
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1)
            cout << ",";
    }
    cout << "]";
}
int main() {
    int n = 3;
    vector<Node*> trees = generateTrees(n);
    cout << "For n = "<<n<<" Total unique BSTs: " << trees.size() << endl;
    for (int i = 0; i < trees.size(); i++) {
        cout << "Tree " << i + 1 << ": ";
        printLevelOrder(trees[i]);
        cout << endl;
    }
    return 0;
}
