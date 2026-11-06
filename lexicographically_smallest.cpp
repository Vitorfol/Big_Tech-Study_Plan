class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        
        int group_id = 0;
        unordered_map<int, int> num_to_group;
        vector<queue<int>> group_values;
        
        group_values.push_back(queue<int>());
        group_values[0].push(sorted_nums[0]);
        num_to_group[sorted_nums[0]] = 0;
        
        for (int i = 1; i < n; ++i) {
            if (sorted_nums[i] - sorted_nums[i - 1] > limit) {
                ++group_id;
                group_values.push_back(queue<int>());
            }
            group_values[group_id].push(sorted_nums[i]);
            num_to_group[sorted_nums[i]] = group_id;
        }
        
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int g = num_to_group[nums[i]];
            ans[i] = group_values[g].front();
            group_values[g].pop();
        }
        
        return ans;
    }
};
