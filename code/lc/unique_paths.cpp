class Solution {
public:

    int dp(int cr, int cc, vector<vector<int>>& memo) {
        if (cr < 0 || cc < 0 || cr > memo.size() || cc > memo[0].size()) return 0;

        if (memo[cr][cc] != 0) return memo[cr][cc];

        if ((cr == 1 && cc == 0) || (cr == 0 && cc == 1) || (cr == 00 && cc == 0)) {
            memo[cr][cc] = 1;
            return 1;
        }

        memo[cr][cc] = dp(cr, cc-1, memo) + dp(cr-1, cc, memo);
        return memo[cr][cc];
    }


    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, 0));
        return dp(m-1, n-1, memo);
    }
};
