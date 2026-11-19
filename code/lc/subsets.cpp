class Solution {
public:
    void possibilities_computation(vector<vector<int>>& answer, int current) {
        for (auto vec : answer) {
            if (vec.size() == 1 && vec[0] == current) continue;
            vec.push_back(current);
            answer.push_back(vec);
        }
    } 
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        int size = static_cast<int>(nums.size());
        answer.reserve(pow(2, size));
            
        for (size_t i=0; i<size; ++i) {
            int current = nums[i];
            answer.push_back({current});
            possibilities_computation(answer, current);
        }

        answer.push_back({});

        return answer;
    }
};

