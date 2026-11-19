/*
Idea: 
We can iterate forward and keep a sum of values of input at the current index and keep track of past values, so we can calculate the complement needed (complement = current_sum - k) and check if we already passed for this value, if we do increment the counter of our solution in how many times we've seen the complement, we start seen 0 once so if we receive [2] k = 2, complement would be 0, and there is one possible solution. and for example in 
1 -1 2 we should return 2 ([2] and [1 -1 2]) and the seen of 0 is 2 and the complement for curr_sum = 2 is 0. So we keep track of how many times in the past our complement has been achieved and sum it. 

how it would work for our input 
nums = [1, 2, 3], k = 3
output = 0;

i=0
        v
nums = [1, 2, 3], k = 3

cs = 1 
seen: 0 1, 

i=1
           v
nums = [1, 2, 3], k = 3

cs = 3  
seen: 0 1, 1 1,  
complement = 3 - 3 = 0. complement[0] = 1, so output++ (= 1 now )

i=2
               v
nums = [1, 2, 3], k = 3

cs = 6
seen: 0 1, 1 1, 3 1
complement = 6 - 3 = 3 (exist once in our seen) so output += 1 (outout = 2 now)

output = 2 
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        size_t size = nums.size();
        unordered_map<int, int> seen;
        seen.reserve(size);

        seen[0] = 1;

        int curr_sum = 0;
        int output = 0;

        for (size_t i=0; i<size; ++i) {
            curr_sum += nums[i];
            int complement = curr_sum - k;
            if (seen.contains(complement)) output += seen[complement];
            ++seen[curr_sum];
        }

        return output;
    }
};
