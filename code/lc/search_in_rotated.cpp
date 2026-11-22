class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while (left <= right) {

            int mid = left + (right-left) / 2;
            if (nums[mid] == target) return mid;

            if (nums[left] <= nums[mid]) {
                if (target < nums[mid] && target >= nums[left]) right = mid-1;
                else left = mid+1;
            }
            else {
                if (target > nums[mid] && target <= nums[right]) left = mid+1;
                else right = mid-1;
            }
        }
        return -1;
    }
};

/*

Idea: discover what half is sorted and check if the target is in boundaries of the sorted interval, if so we took this half, if it 
doesnt we pick up the other half

Code runs in (logn) and has O(1) for memory complexity 

*/
