class Solution {
public:

    int dp(string_view text1, string_view text2, int i, int j, vector<vector<int>>& memo) {
        if (i == text1.size() || j == text2.size()) return 0;

        if (memo[i][j] != -1) return memo[i][j];

        if (text1[i] == text2[j]) {
            memo[i][j] = 1 + dp(text1, text2, i+1, j+1, memo);
        } 
        else {
            int skip1 = dp(text1, text2, i+1, j, memo);
            int skip2 = dp(text1, text2, i, j+1, memo);
            memo[i][j] = max(skip1, skip2);
        }

        return memo[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));
        return dp(text1, text2, 0, 0, memo);
    }
};
