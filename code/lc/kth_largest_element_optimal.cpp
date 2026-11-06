// Try to solve it to run in O(nlogk). Already solved in O(nlogn).

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (size_t i=0; i<nums.size(); ++i) {
            if (k > 0) {
                pq.push(nums[i]);
                --k;
                continue;
            }

            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top(); 
    }

};
