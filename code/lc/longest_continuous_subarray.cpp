#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> window;
        int max_size = 1;
        int l = 0;
        window.insert(nums[l]);
        
        for (int r=1; r<nums.size(); r++) {
            window.insert(nums[r]);

            while (*window.rbegin() - *window.begin() > limit) {
                window.erase(window.find(nums[l]));
                l++;
            }

            max_size = max(max_size, (int)window.size());
        }
        return max_size;
    }
};


int main() {
    Solution sol;
    int n; cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }
    int limit; cin >> limit;
    cout << sol.longestSubarray(nums, limit) << endl;
    return 0;
}