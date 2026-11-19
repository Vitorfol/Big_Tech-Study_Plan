/* 

Approach: sort by end and compare current_end with new_start if new_start is <  our current_end add our counter

*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto sort_by_end = [](const vector<int>& v1, const vector<int>& v2) {
            return v1[1] < v2[1];
        };

        sort(intervals.begin(), intervals.end(), sort_by_end);

        int count = 0;
        int last_end = 0;

        for (size_t i=1; i<intervals.size(); ++i) {
            if (intervals[i][0] >= intervals[last_end][1]) {
                last_end = i;
                continue;
            }
            ++count;
        }

        return count;
    }
};
