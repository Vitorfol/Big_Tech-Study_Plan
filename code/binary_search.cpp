#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size()-1;
	
	while (left <= right) {
		int mid = left + (right-left)/2;
		if (target == nums[mid]) return mid;
		else if(target > nums[mid]) left = mid+1;
		else right = mid-1;
	}

	return -1;
    }
};


int main () {
	vector<int> nums = {1, 2, 3, 4, 6};
	int target; cin >> target;
	Solution sol;
	cout << sol.search(nums, target);
	
	return 0;
}
