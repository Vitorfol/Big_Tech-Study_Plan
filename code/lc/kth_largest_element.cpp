#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        priority_queue<int> pq;
        for (int num : nums) pq.push(num);
        while (k--) 
        {
            int kth = pq.top();
            pq.pop();
            if (k == 0) return kth;
        }
        return -1;
    }
};

int main () {
    Solution s;
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; i++) cin >> nums[i];
    cin >> k;
    cout << s.findKthLargest(nums, k) << endl;

    return 0;
}