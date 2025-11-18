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
	    int minDistance(int dist[], bool visited[]) {
	        int min = INF;
	        int index = 0;
	        for (int i = 0; i < V; i++) {
	            if (!visited[i] && dist[i] < min) {
	                min = dist[i];
	                index = i;
	            }
	        }
	        return index;
	    }
	    void dijkstra(int start) {
	        int dist[50];
	        bool visited[50];
	        for (int i = 0; i < V; i++) {
	            dist[i] = INF;
	            visited[i] = false;
	        }
	        dist[start] = 0;
	        for (int count = 0; count < V - 1; count++) {
	            int u = minDistance(dist, visited);
	            visited[u] = true;
	            for (int v = 0; v < V; v++) {
	                if (!visited[v] && graph[u][v] &&
	                    dist[u] + graph[u][v] < dist[v]) {
	
	                    dist[v] = dist[u] + graph[u][v];
	                }
	            }
	        }
	        cout << "Shortest distances from node " << start << ":\n";
	        for (int i = 0; i < V; i++) {
	            cout << "To " << i << " : " << dist[i] << "\n";
	        }
	    }
};
int main() {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(4, 1, 3);
    g.addEdge(4, 2, 9);
    g.addEdge(2, 3, 4);
    g.dijkstra(0);
    return 0;
}
