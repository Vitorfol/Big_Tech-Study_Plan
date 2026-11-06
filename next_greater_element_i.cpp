class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> memo;
        stack<int> s;
        for (int i=0; i<static_cast<int>(nums2.size()); ++i) {
            int curr = nums2[i];
            while (!s.empty() && curr > nums2[s.top()]) {
                memo[nums2[s.top()]] = curr;
                s.pop();
            }
            s.push(i);
        }

        vector<int> ans;
        for (int curr : nums1) memo.contains(curr) ? ans.push_back(memo[curr]) : ans.push_back(-1); 
        return ans;
    }
};
