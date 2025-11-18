#include <iostream>
#include <vector>
using namespace std;
class IslandCounter {
private:
    int M, N;
    vector< vector<int> > grid;
    void dfs(int r, int c, vector< vector<bool> > &visited) {
        visited[r][c] = true;
        int dr[4] = { -1, 1, 0, 0 };
        int dc[4] = { 0, 0, -1, 1 };
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < M && nc >= 0 && nc < N) {
                if (!visited[nr][nc] && grid[nr][nc] == 1) {
                    dfs(nr, nc, visited);
                }
            }
        }
    }
public:
    IslandCounter(int M, int N) {
        this->M = M;
        this->N = N;
        grid.resize(M, vector<int>(N, 0));
    }
    void setCell(int r, int c, int val) {
        grid[r][c] = val;
    }
    int countIslands() {
        vector< vector<bool> > visited(M, vector<bool>(N, false));
        int count = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                    dfs(i, j, visited);
                }
            }
        }
        return count;
    }
};
int main() {
    int M, N;
    cout << "=====================================\n";
    cout << "          NUMBER OF ISLANDS\n";
    cout << "=====================================\n\n";
    cout << "Enter number of rows (M): ";
    cin >> M;
    cout << "Enter number of columns (N): ";
    cin >> N;
    IslandCounter ic(M, N);
    cout << "\nEnter the grid (0 = water, 1 = land):\n";
    for (int i = 0; i < M; i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            ic.setCell(i, j, x);
        }
    }
    int result = ic.countIslands();
    cout << "\n=====================================\n";
    cout << "              RESULT\n";
    cout << "=====================================\n";
    cout << "Number of islands: " << result << endl;
    cout << "=====================================\n";
    return 0;
}
