#include <vector>

using namespace std;

class Solution {
private:
    int m, n;

    void dfs(int r, int c, int prevHeight, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || heights[r][c] < prevHeight) {
            return;
        }

        visited[r][c] = true;

        dfs(r - 1, c, heights[r][c], heights, visited);
        dfs(r + 1, c, heights[r][c], heights, visited);
        dfs(r, c - 1, heights[r][c], heights, visited);
        dfs(r, c + 1, heights[r][c], heights, visited);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r == 0 || c == 0) {
                    dfs(r, c, INT_MIN, heights, pacific);
                }
                if (r == m - 1 || c == n - 1) {
                    dfs(r, c, INT_MIN, heights, atlantic);
                }
            }
        }

        vector<vector<int>> result;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};
