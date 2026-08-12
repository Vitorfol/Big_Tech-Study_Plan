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
                    dfs(grid, i, j, visited);
                }
            }
        }
        return num_islands;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        bool inbounds = (i >= 0 && i<grid.size() && j >= 0 && j<grid[0].size());
        if (!inbounds || grid[i][j] == '0' || visited[i][j]) return;
        
        visited[i][j] = true;
        dfs(grid, i+1, j, visited);
        dfs(grid, i-1, j, visited);
        dfs(grid, i, j+1, visited);
        dfs(grid, i, j-1, visited);
    }
};
