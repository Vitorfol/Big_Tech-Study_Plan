class Solution {
public:

    unordered_map<int, int> memo;

    int climbStairs(int n) {
        if (n == 2 || n == 1) return n;
        if (memo.contains(n)) return memo[n];

        int steps = climbStairs(n-1) + climbStairs(n-2);
        memo[n] = steps;
        return steps;
    }
};
