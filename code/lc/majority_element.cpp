#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> elements_counter;
        int count_target = ceil(nums.size()/2.0);
        for (int num : nums) {
            elements_counter[num]++;
            if (elements_counter[num] == count_target) return num;
        }
        return -1;
    }
};

int main () {
    Solution solution;
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << solution.majorityElement(nums) << endl;
}