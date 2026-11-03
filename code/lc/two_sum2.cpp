class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        size_t l = 0;
        size_t r = numbers.size()-1;
        int curr_sum = 0;
        
        while (l<r) { 

            // the while (l<r) is the only part of code that is not an assigment or a check (if) code statement, so is the only part that is not constant. since we are iterating the array just one time and increasing left pointer or dicreasing right pointer, it just iterate for our array once, because of that O(N)  time complexity and O(1) memory complexity

            curr_sum = numbers[l] + numbers[r];
            if (curr_sum == target) return {static_cast<int>(l+1), static_cast<int>(r+1)};
            
            if (curr_sum < target) l++;
            else r--;    
        }

        // unreachable since the problem statement restrict that we must have a valid solution as an input of our test
        return {-1, -1};
    }
};
