/*

0: 
2 1 1 
1 1 0
0 1 1

1: 
2 2 1
2 1 0
0 1 1

2: 
2 2 2 
2 2 0
0 1 1

3: 
2 2 2 
2 2 0
0 2 1

4: 
2 2 2 
2 2 0
0 2 2

For each iteration we call a bfs that mark cells that are 1 that has a neighbor being 2, it becomes 2. But i think that is dangeour just changed it in real time. Because we can modify in chain, probably its safer save an array of elements that will be changed

*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> processed_twos;
        int nums_of_one = 0;

        for (size_t i=0; i<grid.size(); ++i) {
            for (size_t j=0; j<grid[0].size(); ++j) {
                if (grid[i][j] == 2) processed_twos.push({i, j});
                if (grid[i][j] == 1) ++nums_of_one;
            }
        }

        int minutes = 0;

        while (!processed_twos.empty() && nums_of_one >= 1) {
            size_t size = processed_twos.size();
            
            for (size_t i=0; i<size; ++i) {
                auto [r, c] = processed_twos.front();
                processed_twos.pop();

                for (auto [dr, dc] : directions) {
                    int nr = r+dr;
                    int nc = c+dc;
                    if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size()) continue;

                    if (grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        --nums_of_one;
                        processed_twos.push({nr, nc});
                    } 
                }
            }
            ++minutes;
        }
        return nums_of_one > 0 ? -1 : minutes;
    }
};
