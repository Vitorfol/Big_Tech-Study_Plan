class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char, int> mapping;
        int max_chars = s.size();
        mapping.reserve(max_chars);

        for (char caracter : s) mapping[caracter]++;

        int count = 0;
        bool has_odd = false;
        for (auto map : mapping) {
            int freq = map.second;
            count +=freq;
            if (freq%2!=0) {
                count--;
                has_odd = true;
            }
        }

        if (has_odd) count++;
        return count;
    }
};
