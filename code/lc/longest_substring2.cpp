#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> aux;
        int size = s.size();
        aux.reserve(size);
        int l = 0;
        int max_len = 0;

        for (int r=0; r<size; r++) {
            char curr = s[r];

            auto it = aux.find(curr);
            if (it != aux.end()) {
                auto [caracter, last] = *it;
                if (aux[curr] >= l)l = last + 1;
            }

            aux[curr] = r;
            max_len = max(max_len, r-l+1);
        }
        return max_len;
    }
};