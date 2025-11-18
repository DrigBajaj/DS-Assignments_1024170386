#include <iostream>
#include <vector>
using namespace std;
class Edge {
	public:
	    int u, v, w;
};
class Graph {
	private:
	    int V;
	    vector<Edge> edges;
	    int findParent(int parent[], int x) {
	        if (parent[x] == x) return x;
	        return findParent(parent, parent[x]);
	    }
	    void bubbleSortEdges() {
	        for (int i = 0; i < edges.size() - 1; i++) {
	            for (int j = 0; j < edges.size() - i - 1; j++) {
	                if (edges[j].w > edges[j + 1].w) {
	                    Edge temp = edges[j];
	                    edges[j] = edges[j + 1];
	                    edges[j + 1] = temp;
	                }
	            }
	        }
	    }
	public:
	    Graph(int V) {
	        this->V = V;
	    }
	    void addEdge(int u, int v, int w) {
	        Edge e;
	        e.u = u;
	        e.v = v;
	        e.w = w;
	        edges.push_back(e);
	    }
	    void KruskalMST() {
	        bubbleSortEdges();
	        int parent[100];
	        for (int i = 0; i < V; i++) parent[i] = i;
	        cout << "Edges in MST:\n";
	        for (int i = 0; i < edges.size(); i++) {
	            int pu = findParent(parent, edges[i].u);
	            int pv = findParent(parent, edges[i].v);
	            if (pu != pv) {
	                cout << edges[i].u << " - " << edges[i].v
	                     << " : " << edges[i].w << "\n";
	                parent[pu] = pv;
	            }
	        }
	    }
};
int main() {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.KruskalMST();
    return 0;
}
