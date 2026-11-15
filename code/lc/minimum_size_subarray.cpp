
#include <math.h>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:

    int left_position(const vector<int>& nums, const int& left, const int& right, const int& target, int& current_sum) {
        for (int i=left; i<=right; ++i) {
            if (current_sum - nums[i] >= target) {
                current_sum -= nums[i];
                continue;
            }
            return i;
        }
        return -1;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        
        int min_sub = INT_MAX;
        int current_sum = 0;
        int left = 0;

        for (int right=0; right<static_cast<int>(nums.size()); right++) {
            current_sum += nums[right];
            if (current_sum < target) continue;

            left = left_position(nums, left, right, target, current_sum);
    
            min_sub = min(min_sub, right-left+1);
        }

        if (min_sub == INT_MAX) min_sub = 0;
        return min_sub;
    }
    //         v v
    // 2,3,1,2,4,3           | target_sum = 7
    // cs = 7
    // min_sub = 2
};
