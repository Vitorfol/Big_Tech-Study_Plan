/*

Approach: 

For each number in the input we create a candidate(nums.size()) and the index that the number is is already filled and we do each variation for the others 

example 

1, 2, 3
output = 


1 

output = 1, 2, 3 | 1, 3, 2

2 
output = 1, 2, 3 | 1, 3, 2 | 2, 1, 3 | 2, 3, 1

*/

class Solution {
public:
    void backtracking(vector<vector<int>>& answer, const vector<int>& nums, vector<int> current, int original, vector<bool>& used) {
        
        if (current.size() == nums.size()) {
            answer.push_back(current);
        }

        for (int i=0; i<static_cast<int>(nums.size()); ++i) {
            if (used[i]) continue;
            used[i] = true;
            current.push_back(nums[i]);
            backtracking(answer, nums, current, i, used);
            current.pop_back();
            used[i] = false;
        }

    }

    vector<vector<int>> permute(vector<int>& nums) { // runs in O(N!)
        vector<vector<int>> answer;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        backtracking(answer, nums, current, 0, used);
        return answer;
    }
};
