class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> memo; 
        int current_sum = 0;
        int current_interval;
        int max_interval = 0;
        memo[0] = -1;
        for (int i=0; i<static_cast<int>(nums.size()); i++) {
            current_sum += (nums[i] > 0)? 1 : -1;
            if (memo.contains(current_sum)) {
                int current_interval = i - memo[current_sum];
                max_interval = max(max_interval, current_interval);
            }
            else memo[current_sum] = i;
        }
        return max_interval;
    }
};
