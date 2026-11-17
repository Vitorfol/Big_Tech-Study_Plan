class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;

        size_t n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {1, 1}, {-1, -1}, {1, -1}};

        queue<pair<int, int>> to_visit;
        to_visit.push({0, 0});

        int path_distance = 0;

        while (!to_visit.empty()) {
            size_t size = to_visit.size();
            for (size_t i=0; i<size; ++i) {
                auto [r, c] = to_visit.front();

                if (r == n-1 && c == n-1) return ++path_distance;

                to_visit.pop();

                for (auto [dr, dc] : directions) {
                    int nr = r+dr;
                    int nc = c+dc;

                    if (nr < 0 || nc < 0 || nr >= n || nc >= n || visited[nr][nc] || grid[nr][nc] == 1) continue;

                    visited[nr][nc] = true;
                    to_visit.push({nr, nc});
                }
            }
            ++path_distance;
        }
        return -1;
    }
};
