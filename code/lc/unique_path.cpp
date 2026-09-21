#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int recur(vector<vector<int>>& mat, int m, int n) {
        if (m < 0 || n < 0) return 0;

        if (m == 0 || n == 0) {
            mat[m][n] = 1;
            return 1;
        }

        if (mat[m][n] != -1) return mat[m][n];

        mat[m][n] = recur(mat, m-1, n) + recur(mat, m, n-1);
        return mat[m][n]; 
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> mat(m, vector<int>(n, -1));
        int result = recur(mat, m-1, n-1);
        return result;     
    }

};

int main() {
    int m, n; cin >> m >> n;
    Solution solution;
    cout << solution.uniquePaths(m, n);
}