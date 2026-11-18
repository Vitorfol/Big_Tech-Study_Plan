/*

intervals = [[1,3],[2,6],[8,10],[15,18]]
output = [[1,6],[8,10],[15,18]]

Idea: Sort intervals so we can know which intervals we do merge and create a vector of vectors, each vector represents the start and end of each merged interval. The first one will be the index 0 after sort and compare the start of the next with the end of the previous, if they match we just merge, if dont we create a new vector 

Example for: [[1,3],[2,6],[8,10],[15,18]]

already sort -> [[1,3],[2,6],[8,10],[15,18]]
                          v
solution starts with [[1, 3]]

                                         v
now we start iterate and compare [[1,3],[2,6],[8,10],[15,18]]

2 is <= than 3 (start[new] <= end[old]) so we merge update the end of old with the end being the max(new[end], old[end])
               v
solutions [[1, 6]]
              v
[[1,3],[2,6],[8,10],[15,18]]
8 is not <= 6 so we create a new vector and add the current one
                                  v
solutions solutions [[1, 6], [8, 10]]
                      v
[[1,3],[2,6],[8,10],[15,18]]


again 15 is not <= 10 so we create again a new one
solutions solutions [[1, 6], [8, 10], [15, 18]]


[[4, 7], [1, 4]]

[[1, 4], [4, 7]]

end_index = 0;
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        size_t size = intervals.size();
        vector<vector<int>> answer;
        answer.reserve(size);
        
        sort(intervals.begin(), intervals.end());
        answer.push_back(intervals[0]);
        int end_index = 0;

        for (size_t i=1; i<size; ++i) {
            if (intervals[i][0] <= answer[end_index][1]) {
                answer[end_index][1] = max(answer[end_index][1], intervals[i][1]);
                continue;
            }
            answer.push_back(intervals[i]);
            ++end_index;
        }
        return answer;
    }
};