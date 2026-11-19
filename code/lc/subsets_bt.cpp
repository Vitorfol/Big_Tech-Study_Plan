class Solution {
public:

    void backtracking(vector<vector<int>>& answer, vector<int>& current, const vector<int>& nums, int start) {

        answer.push_back(current);

        for (size_t i=start; i<nums.size(); ++i) {
            current.push_back(nums[i]);
            backtracking(answer, current, nums, i+1);
            current.pop_back();
        }
    } 

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> current;
        int start = 0;

        backtracking(answer, current, nums, start);
        return answer;
    }
};
