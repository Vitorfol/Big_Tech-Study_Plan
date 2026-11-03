#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void expandir(string& s, int left, int right, int& best_start, int& highest) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            int curr = right-left+1;
            if (curr > highest) {
                highest = curr;
                best_start = left;
            }
            left--;
            right++;
        }   
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size()==1) return s;

        int best_start = 0;
        int highest = 1;

        for (int i=0; i<s.size(); i++) {
            expandir(s, i, i, best_start, highest);
            expandir(s, i, i+1, best_start, highest);
        }

        return s.substr(best_start, highest);

    }
};

int main() {
    Solution sol;
    string s; cin >> s;
    cout << sol.longestPalindrome(s) << endl;
}