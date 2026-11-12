#include <bits/stdc++.h>
using namespace std;

/* 

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Idea: Monotonic Stack
A Monotonic Stack allows to determine when we find a daily temp that is larger than our current value. So looks like the perfect data structure for this problem


Input: 73,74,75,71,69,72,76,73

1, 1, 4, 2, 1, 0, 0

We create a vector<int> solution that starts with everything being 0 

We create a stack that stores indexes, when we find a value of a index that is greater than our current, we pop in loop

How it would work

       0  1  2  3  4  5  6  7
Input: 73,74,75,71,69,72,76,73

Solution: 1, 1, 4, 2, 1, 1, 0, 0

       7
Stack: 6

*/ 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        size_t size = temperatures.size();
        vector<int> solution(size, 0);
        stack<int> monotonic_stack;

        for (size_t i=0; i<size; ++i) {
            while (!monotonic_stack.empty() && temperatures[i] > temperatures[monotonic_stack.top()]) {
                solution[monotonic_stack.top()] = i - monotonic_stack.top();
                monotonic_stack.pop();
            }

            monotonic_stack.push(i);
        }

        return solution;
    }
};

int main() {

	Solution solution;
	int n; cin >> n;
	vector<int> input;
	while (n--) {
		int aux; cin >> aux;
		input.push_back(aux);
	}
	vector<int> sol = solution.dailyTemperatures(input);
	for (int v : sol) cout << v << " ";
	return 0; 
}
