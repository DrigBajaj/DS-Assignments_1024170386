#include <iostream>
#include <vector>
using namespace std;
#define INF 999999
class Graph {
	private:
	    int V;
	    vector< vector<int> > graph;
	public:
	    Graph(int V) {
	        this->V = V;
	        graph.resize(V, vector<int>(V, 0));
	    }
	    void addEdge(int u, int v, int w) {
	        graph[u][v] = w;
	        graph[v][u] = w;
	    }
	    int minKey(int key[], bool mstSet[]) {
	        int min = INF;
	        int index = 0;
	        for (int v = 0; v < V; v++) {
	            if (!mstSet[v] && key[v] < min) {
	                min = key[v];
	                index = v;
	            }
	        }
	        return index;
	    }
	    void PrimMST() {
	        int parent[50];
	        int key[50];
	        bool mstSet[50];
	        for (int i = 0; i < V; i++) {
	            key[i] = INF;
	            mstSet[i] = false;
	        }
	        key[0] = 0;
	        parent[0] = -1;
	        for (int count = 0; count < V - 1; count++) {
	            int u = minKey(key, mstSet);
	            mstSet[u] = true;
	            for (int v = 0; v < V; v++) {
	                if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
	                    parent[v] = u;
	                    key[v] = graph[u][v];
	                }
	            }
	        }
	        cout << "Edges in MST:\n";
	        for (int i = 1; i < V; i++) {
	            cout << parent[i] << " - " << i
	                 << " : " << graph[i][parent[i]] << "\n";
	        }
	    }
};
int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);
    g.PrimMST();
    return 0;
}
