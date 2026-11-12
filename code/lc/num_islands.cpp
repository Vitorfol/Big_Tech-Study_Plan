#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void travel(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int cr, int cc) {
        if (cr < 0 || cr >= grid.size() || cc < 0 || cc >= grid[0].size() || visited[cr][cc] || grid[cr][cc] == '0') return;

        visited[cr][cc] = true;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto direction : directions) {
            travel(grid, visited, cr+direction.first, cc+direction.second);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        size_t m = grid.size();
        size_t n = grid[0].size();
        vector<vector<bool>> visited (m, vector<bool>(n, false));

        int num_islands = 0;
        for (size_t i=0; i<m; ++i) {
            for (size_t j=0; j<n; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    travel(grid, visited, i, j);
                    ++num_islands;
                }
            }
        }
        
        return num_islands;
    }
};

int main() {

    Solution solution;

    vector<vector<char>> input = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    cout << solution.numIslands(input);

    cout << endl;

    vector<vector<char>> input2 = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
    cout << solution.numIslands(input2);
}