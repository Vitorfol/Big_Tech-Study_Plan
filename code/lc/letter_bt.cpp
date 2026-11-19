class Solution {
public:
    void fill_mapping(unordered_map<char, string>& mapping) {
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";
    }

    void backtracking(const string& digits, vector<string>& answer, int index, unordered_map<char, string>& mapping, string& current) {

        if (current.size() == digits.size()) {
            answer.push_back(current);
            return;
        }

        for (char character : mapping[digits[index]]) {
            current.push_back(character);
            backtracking(digits, answer, index+1, mapping, current);
            current.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mapping;
        mapping.reserve(9);
        vector<string> answer;
        string current;

        fill_mapping(mapping);
        backtracking(digits, answer, 0, mapping, current);
        return answer;
    }
};
