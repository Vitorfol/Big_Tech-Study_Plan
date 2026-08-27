class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, curr_sum = 0, min_len = 1e9;

        for (int right=0; right<nums.size(); right++)
        {
            curr_sum += nums[right];

            while (curr_sum >= target) {
                min_len = min(min_len, right-left+1);
                curr_sum -= nums[left];
                left++;
            }  
        }

        return min_len == 1e9 ? 0 : min_len; 
    }
};