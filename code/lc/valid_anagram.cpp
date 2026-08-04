    class Solution {
    public:
        bool isAnagram(string s, string t) {
            if (s.size() != t.size()) return false;

            unordered_map<char,int> chars;
            chars.reserve(s.size());
            for (char caracter : s) chars[caracter]++;
            for (char caracter : t) {
                if (chars[caracter] == 0) return false;
                chars[caracter]--;
            } 
            return true;
        }
    };