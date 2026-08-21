#include <iostream>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int max_len = 0;
        int left = 0; 

        unordered_map<char, int> auxiliar; 
        auxiliar.reserve(size);
        
        for (int i = 0; i < size; i++) {
            char da_vez = s[i];

            if (auxiliar.contains(da_vez) && auxiliar[da_vez] >= left) {
                left = auxiliar[da_vez] + 1;
            }

            auxiliar[da_vez] = i; 
            max_len = max(max_len, i - left + 1); 
        }

        return max_len;
    }
};

int main() {
    Solution sol;
    string test;
    cout << "Enter a string: ";
    cin >> test;
    cout << "Result: " << sol.lengthOfLongestSubstring(test) << endl;
    return 0;
}