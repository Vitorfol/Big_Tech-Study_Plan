#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums ) count[num]++;
        vector<pair<int, int>> freq; 
        for (auto reg : count) freq.push_back({reg.second, reg.first});
        sort(freq.begin(), freq.end(), greater<pair<int, int>>());
        vector<int> top_k(k);
        for (int i=0; i<k; i++) top_k[i] = (freq[i].second);
        return top_k;
    }
};
