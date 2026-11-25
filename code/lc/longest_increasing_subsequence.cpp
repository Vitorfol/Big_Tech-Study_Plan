class Solution {
public:

    int dp(int index, vector<vector<int>>& memo, const vector<int>& nums, int prev_index) {
        if (index >= nums.size()) return 0;

        if (memo[index][prev_index+1] != -1) return memo[index][prev_index+1]; 

        int skip = dp(index+1, memo, nums, prev_index);
        int get = 0;
        if (prev_index == -1 || nums[index] > nums[prev_index]) {
            get = 1 + dp(index+1, memo, nums, index);
        }

        memo[index][prev_index+1] = max(skip, get);
        return memo[index][prev_index+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), -1));
        return dp(0, memo, nums, -1);
    }
};
