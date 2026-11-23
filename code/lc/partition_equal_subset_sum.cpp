class Solution {
public:

    bool combine(int i, int rem, const vector<int>& nums, vector<vector<int>>& memo) {
        if (rem == 0) return true;

        if (rem < 0 || i == nums.size()) return false;
    
        if (memo[i][rem] != -1) return memo[i][rem];

        bool skip = combine(i+1, rem, nums, memo);
        bool get = combine(i+1, rem-nums[i], nums, memo);

        memo[i][rem] = (skip || get);
        return memo[i][rem]; 
    }

    bool canPartition(vector<int>& nums) {
        int soma = 0;
        for (int num : nums) soma += num;

        if (soma % 2 != 0) return false;

        int half = soma / 2;

        vector<vector<int>> memo(nums.size(), vector<int>(half+1, -1));

        return combine(0, half, nums, memo);
    }
};
