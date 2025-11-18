#include <iostream>
#include <vector>
using namespace std;
class Graph {
	private:
	    int V;
	    vector< vector<int> > adj;
	    void DFSUtil(int node, vector<bool> &visited) {
	        visited[node] = true;
	        for (int i = 0; i < adj[node].size(); i++) {
	            int next = adj[node][i];
	            if (!visited[next]) {
	                DFSUtil(next, visited);
	            }
	        }
	    }
	public:
	    Graph(int V) {
	        this->V = V;
	        adj.resize(V);
	    }
	    void addEdge(int u, int v) {
	        adj[u].push_back(v);
	        adj[v].push_back(u);
	    }
	    int countConnectedComponents() {
	        vector<bool> visited(V, false);
	        int count = 0;
	        for (int i = 0; i < V; i++) {
	            if (!visited[i]) {
	                count++;
	                DFSUtil(i, visited);
	            }
	        }
	        return count;
	    }
};
int main() {
    int V, E, u, v;
    cout << "Enter number of vertices (V) and edges (E): ";
    cin >> V >> E;
    Graph g(V);
    cout << "Enter each edge as: u v\n";
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    int components = g.countConnectedComponents();
    cout << "\n==============================\n";
    cout << "   GRAPH CONNECTIVITY RESULT   \n";
    cout << "==============================\n";
    cout << "Total Vertices: " << V << "\n";
    cout << "Total Edges: " << E << "\n";
    cout << "Connected Components: " << components << "\n";
    cout << "==============================\n";
    return 0;
}
