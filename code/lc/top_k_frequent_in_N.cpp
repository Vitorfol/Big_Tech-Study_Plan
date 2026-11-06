/* 
          
          3 -> 1
          2 -> 3
          4 -> 1
          1 -> 4      
*/ 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        size_t nums_size = nums.size();
        unordered_map<int, int> count;
        count.reserve(nums_size);

        for (int num : nums) ++count[num];

        vector<vector<int>> buckets(nums_size+1);
        for (const auto& [v, f] : count) {
            buckets[f].push_back(v);
        }

        vector<int> ans;
        ans.reserve(k);
        for (int i=static_cast<int>(nums_size); i>=1; --i) {
            for (int v : buckets[i]) {
                ans.push_back(v);
                if (static_cast<int>(ans.size()) == k) return ans;
            }
        }
        return ans;
    }
};
