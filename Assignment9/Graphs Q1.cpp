#include <iostream>
#include <queue>
using namespace std;
class Graph {
    int V;
    int **adj;
	public:
	    Graph(int V) {
	        this->V = V;
	        adj = new int*[V];
	        for (int i = 0; i < V; i++) {
	            adj[i] = new int[V];
	            for (int j = 0; j < V; j++)
	                adj[i][j] = 0;
	        }
	    }
	    void addEdge(int u, int v) {
	        adj[u][v] = 1;
	        adj[v][u] = 1;
	    }
	    void BFS(int start) {
	        bool *visited = new bool[V];
	        for (int i = 0; i < V; i++)
	            visited[i] = false;
	        queue<int> q;
	        visited[start] = true;
	        q.push(start);
	        cout << "BFS Traversal starting from node 0: ";
	        while (!q.empty()) {
	            int node = q.front();
	            q.pop();
	            cout << node << " ";
	            for (int i = 0; i < V; i++) {
	                if (adj[node][i] == 1 && !visited[i]) {
	                    visited[i] = true;
	                    q.push(i);
	                }
	            }
	        }
	        cout << endl;
	    }
};
int main() {
    int V = 5;
    Graph g(V);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.BFS(0);
    return 0;
}
