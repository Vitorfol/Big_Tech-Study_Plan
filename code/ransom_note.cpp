#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> counter;
        for(char caracter : magazine) {
            counter[caracter]++;
        }

        for(auto caracter : ransomNote) {
            cout << "Current caracter: " << caracter << ". Current count on magazine: " << counter[caracter] << endl;
            if (counter[caracter] == 0) return false;
            counter[caracter]--;
        }

        return true;
    }
};

int main() {
	string ransomNote, magazine; cin >> ransomNote >> magazine;
    Solution solution;
	bool result = solution.canConstruct(ransomNote, magazine);
    cout << result;
	return 0;
}