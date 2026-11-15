/*


     v    
abcabcbb
   ---

a -> 3
b -> 4
c -> 2

cw = 3
mw = 3

===========

     v
pwwkew
   ---
p -> 0
w -> 5
k -> 3
e -> 4

cw = 3
mw = 3

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> memory;
        memory.reserve(s.size());
        
        int left = 0;
        int max_window = 0;

        for (int i=0; i<static_cast<int>(s.size()); ++i) {
            if (memory.contains(s[i]) && memory[s[i]]+1 > left) left = memory[s[i]]+1;
            memory[s[i]] = i;
            max_window = max(max_window, i-left+1);
        }

        return max_window;
    }
};

int main() {
    Solution solution;
    string s1 = "abcabcbb";
    assert(solution.lengthOfLongestSubstring(s1) == 3);

    string s2 = "bbbbb";
    assert(solution.lengthOfLongestSubstring(s2) == 1); 

    string s3 = "ccbbcc";
    assert(solution.lengthOfLongestSubstring(s3) == 2);
}