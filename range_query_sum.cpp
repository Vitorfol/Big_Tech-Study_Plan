class NumArray {
public:
    NumArray(vector<int>& nums) {
        this->prefix.resize(nums.size());
        prefix[0] = nums[0];
        for (size_t i=1; i<nums.size(); ++i) prefix[i] = prefix[i-1] + nums[i];
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return prefix[right];
        return prefix[right] - prefix[left-1];
    }
private: 
    vector<int> prefix;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);


-2 0 3 -5 2 -1 -> -2 -2 1 -4 -2 -3 
 
 query: 0-2 -> 1
 query: 2-5 -> -1 
 query: 0-5 -> -3

 if (left == 0) return nums[right];
 return nums[right]-nums[left-1];
 */
