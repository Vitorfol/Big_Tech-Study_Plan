/*

Approach: since we have to run it in O(logn), the picked idea would be a binary search, we look in the middle and follow the increase element making this while left is lower than right, and after this return any pointer since they will be the same 

obs: we look at mid and mid[i+1] to follow the increase element, 

if the increase is for right, we discard left half, 
in another case we make right = mid

[1, 2, 3, 4, 5, 6, 7], 6

 v        v        v 
[1, 2, 3, 4, 5, 6, 7] -> mid is for, the increasing is for right now we have 
 
 v  v  v
[5, 6, 7] -> mid is 6, increasing is for right, but now l = r so we break our loop and return l/r, works

 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = static_cast<int>(nums.size())-1;

        while (left < right) {
            int mid = left + (right-left) / 2;
            if (nums[mid] < nums[mid+1]) left = mid+1;
            else right = mid;
        }
        return left;
    }
};
