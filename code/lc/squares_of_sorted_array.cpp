#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        for (int i=0; i<nums.size(); i++) result[i] = nums[i] * nums[i];
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; i++) cin >> nums[i];
    vector<int> result = sol.sortedSquares(nums);
    for (int num : result) cout << num << " ";
}