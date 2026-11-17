class Solution {
public:
    void travel(vector<vector<char>>& board, int cr, int cc) {
        size_t m = board.size();
        size_t n = board[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> to_process;

        to_process.push({cr, cc});
        board[cr][cc] = '#';

        while (!to_process.empty()) {
            auto front = to_process.front();
            to_process.pop();

            for (auto [dr, dc] : directions) {
                int nr = dr+front.first;
                int nc = dc+front.second;

                if (nr < 0 || nc < 0 || nr >= m || nc >= n || board[nr][nc] != 'O') continue;

                board[nr][nc] = '#';
                to_process.push({nr, nc});
            }
        }
    } 

    void solve(vector<vector<char>>& board) {
        size_t m = board.size();
        size_t n = board[0].size();

        for (size_t i=0; i<m; ++i) {
            for(size_t j=0; j<n; ++j) {
                bool is_edge = (i == 0 || j == 0 || i == m-1 || j == n-1);
                if (board[i][j] == 'O' && is_edge) {
                    travel(board, i, j);
                }
            }
        }

        for (size_t i=0; i<m; ++i) {
            for (size_t j=0; j<n; ++j) {
                if (board[i][j] == '#') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};

/*

Idea: mark cells that cant be changed with "#" starting a travel in board[0][*], board[m-1][*], board[*][0], board[*][n-1]. after this we could wake by the matrix and just replace, where is a # we make it an X and where is X we make an O carefully to dont make a thing like # -> X -> O, a simple check and just one iteration for each cell in the grid should woark 

So, how our algorithm would work for our input:

Phase 0:
X X X X
X O O X
X X O X
X O X X

Phase 1: 
X X X X
X O O X
X X O X
X # X X

Phase 2 (return statement): 
X X X X
X X X X
X X X X
X O X X

*/
