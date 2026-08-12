class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int num_islands = 0; 
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    num_islands++;
                    // implementing w/ bfs now to avoid stackoverflow
                    bfs(grid, i, j, visited);
                }
            }
        }
        return num_islands;
    }

    void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        queue<pair<int, int>> q;

        q.push({i, j});
        visited[i][j] = true;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int r = row + dr;
                int c = col + dc;

                bool valid = r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&grid[r][c] == '1' && !visited[r][c];
                if (!valid) continue;

                visited[r][c] = true;
                q.push({r, c}); 
            }
        }
    }
};