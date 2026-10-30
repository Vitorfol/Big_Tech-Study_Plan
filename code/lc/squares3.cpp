#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        int l= 0;
        int r= size-1;
        vector<int> optimal;
        while (l<=r) {
            int lv = abs(nums[l]);
            int rv = abs(nums[r]);
            if (lv < rv) {
                optimal.push_back(rv*rv);
                r--;
            }
            else {
                optimal.push_back(lv*lv);
                l++;
            }
        }

        reverse(optimal.begin(), optimal.end());
        return optimal;
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
