/*

Basically here we have to find the maximum sum in a contiguous array in a range of n elements. My approach would be create a sliding window that slide from left to right searching the contiguous array that maximize this sum. When we stop iterating the array, we just return max_sum / n; 

The time complexity would be O(n) and the memory complexity would be O(1)

*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        size_t size = nums.size();

        if (k > size) return -1.0;

        int current_sum = 0;
        for (size_t i=0; i<k; ++i) current_sum += nums[i];

        int max_sum = current_sum;

        for (size_t i=k; i<size; ++i) {
            current_sum += nums[i] - nums[i-k];
            max_sum = max(max_sum, current_sum);
        }

        return static_cast<double>(max_sum) / k;
    }
};
