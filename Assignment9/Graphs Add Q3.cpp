#include <iostream>
#include <vector>
using namespace std;
#define INF 999999
class Graph {
	private:
	    int N;
	    vector< vector< pair<int,int> > > adj;
	public:
	    Graph(int N) {
	        this->N = N;
	        adj.resize(N + 1);
	    }
	    void addEdge(int u, int v, int w) {
	        adj[u].push_back(make_pair(v, w));
	    }
	    int dijkstra(int K) {
	        vector<int> dist(N + 1, INF);
	        vector<bool> visited(N + 1, false);
	        dist[K] = 0;
	        for (int step = 0; step < N; step++) {
	            int minVal = INF;
	            int u = -1;
	            for (int i = 1; i <= N; i++) {
	                if (!visited[i] && dist[i] < minVal) {
	                    minVal = dist[i];
	                    u = i;
	                }
	            }
	            if (u == -1) break;
	            visited[u] = true;
	            for (int i = 0; i < adj[u].size(); i++) {
	                int v = adj[u][i].first;
	                int w = adj[u][i].second;
	                if (!visited[v] && dist[u] + w < dist[v]) {
	                    dist[v] = dist[u] + w;
	                }
	            }
	        }
	        int maxTime = 0;
	        for (int i = 1; i <= N; i++) {
	            if (dist[i] == INF) return -1;
	            if (dist[i] > maxTime) {
	                maxTime = dist[i];
	            }
	        }
	        return maxTime;
	    }
};
int main() {
    int N, E, K;
    int u, v, w;
    cout << "=====================================\n";
    cout << "        NETWORK DELAY TIME\n";
    cout << "=====================================\n\n";
    cout << "Enter number of nodes (N): ";
    cin >> N;
    cout << "Enter number of edges (E): ";
    cin >> E;
    cout << "Enter starting node (K): ";
    cin >> K;
    Graph g(N);
    cout << "\nEnter edges as: u v w\n";
    cout << "(Directed edge from u -> v with weight w)\n\n";
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    int result = g.dijkstra(K);
    cout << "\n=====================================\n";
    cout << "               RESULT\n";
    cout << "=====================================\n";
    if (result == -1) {
        cout << "Some nodes cannot be reached from node " << K << ".\n";
        cout << "Network Delay Time: -1\n";
    } else {
        cout << "All nodes received the signal.\n";
        cout << "Network Delay Time: " << result << "\n";
    }
    cout << "=====================================\n";
    return 0;
}
