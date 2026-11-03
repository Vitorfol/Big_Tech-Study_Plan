class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int max_seq = 0;

        auto it = nums_set.begin();
        while(it!=nums_set.end()) {
            int prev = *it-1;
            if (nums_set.contains(prev)) {
                ++it;
                continue;
            }
            int curr_seq = 0;
            while (nums_set.contains(prev+1)) {
                curr_seq++;
                prev++;
            }
            max_seq=max(max_seq, curr_seq);
            ++it;
        }

        return max_seq;
    }
};
