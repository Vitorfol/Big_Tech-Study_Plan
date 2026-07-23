#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        toLowerCaseAndRemoveNonAlphanumeric(s);
        int size = s.size();
        for (int i=0; i<size/2; i++) {
	        bool equal = s[i] == s[size-i-1];
            cout << "current i: " << i << ". current size-i-1: " << size-i-1 << ". equal: " << equal << endl;
            if (!equal)return false;
        }
        return true;
    }
    
    void toLowerCaseAndRemoveNonAlphanumeric(string& s) {
        string result;

        for (char c : s) {
            unsigned char uc = static_cast<unsigned char>(c);

            if (isalnum(uc)) {
                result += static_cast<char>(tolower(uc));
            }
        }

        s = result;
    }

};

int main() {
	string str = "A man, a plan, a canal: Panama";
	Solution solution;
	solution.isPalindrome(str);
	return 0;
}
