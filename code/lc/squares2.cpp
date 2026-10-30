#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        for (int i=0; i<size; i++) nums[i] *= nums[i];
        sort(nums.begin(), nums.end());
        return nums;
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