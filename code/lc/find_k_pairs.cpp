#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;

        int n1 = nums1.size();
        int n2 = nums2.size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> min_heap;

        for (int i = 0; i < n1; ++i) {
            min_heap.push({nums1[i] + nums2[0], {i, 0}});
        }

        while (!min_heap.empty() && result.size() < k) {
            auto top = min_heap.top();
            min_heap.pop();

            int i = top.second.first;  
            int j = top.second.second; 

            result.push_back({nums1[i], nums2[j]});

            if (j + 1 < n2) {
                min_heap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return result;
    }
};
