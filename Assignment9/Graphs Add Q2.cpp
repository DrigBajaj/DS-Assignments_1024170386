#include <iostream>
#include <vector>
using namespace std;
#define INF 999999
class GridGraph {
	private:
	    int m, n;
	    vector< vector<int> > grid;
	public:
	    GridGraph(int m, int n) {
	        this->m = m;
	        this->n = n;
	        grid.resize(m, vector<int>(n, 0));
	    }
	    void setCell(int i, int j, int value) {
	        grid[i][j] = value;
	    }
	    int dijkstra() {
	        int total = m * n;
	        vector<int> dist(total, INF);
	        vector<bool> visited(total, false);
	        dist[0] = grid[0][0];
	        for (int k = 0; k < total - 1; k++) {
	            int minVal = INF;
	            int u = 0;
	            for (int i = 0; i < total; i++) {
	                if (!visited[i] && dist[i] < minVal) {
	                    minVal = dist[i];
	                    u = i;
	                }
	            }
	            visited[u] = true;
	            int r = u / n;
	            int c = u % n;
	            int dr[4] = { -1, 1, 0, 0 };
	            int dc[4] = { 0, 0, -1, 1 };
	            for (int i = 0; i < 4; i++) {
	                int nr = r + dr[i];
	                int nc = c + dc[i];
	                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
	                    int v = nr * n + nc;
	                    if (!visited[v] && dist[u] + grid[nr][nc] < dist[v]) {
	                        dist[v] = dist[u] + grid[nr][nc];
	                    }
	                }
	            }
	        }
	        return dist[total - 1];
	    }
};
int main() {
    int m, n;
    cout << "=============================\n";
    cout << "  SHORTEST PATH IN GRID\n";
    cout << "     (Using Dijkstra)\n";
    cout << "=============================\n\n";
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;
    cout << "\nEnter the grid costs (" << m << " x " << n << "):\n";
    cout << "(Each value should be a non-negative integer)\n\n";
    GridGraph g(m, n);
    for (int i = 0; i < m; i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            g.setCell(i, j, x);
        }
    }
    int result = g.dijkstra();
    cout << "\n=================================\n";
    cout << "         RESULT SUMMARY\n";
    cout << "=================================\n";
    cout << "Start Cell: (0, 0)\n";
    cout << "End Cell:   (" << m - 1 << ", " << n - 1 << ")\n";
    cout << "Minimum Total Cost: " << result << "\n";
    cout << "=================================\n";
    return 0;
}
