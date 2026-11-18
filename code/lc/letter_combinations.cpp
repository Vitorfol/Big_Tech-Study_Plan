/*

2 -> a, b, c
3 -> d, e, f
...
9 -> w, x, y, z

Idea: create an auxiliar function that receive one vector of strings and a vector of chars, and for each string add each char, so we calculate each possibilitie
So for string.empty() we return [] 
if string.size() == 1 we just get the digit with string[0] an return something like 
char = string[0];
mapping[char] iterate and return in any another case we can use this auxiliar function to compute and alterate each possibilitie 

example for 

input: 23 

mapping: 
2 -> a, b, c
3 -> d, e, f
...
9 -> w, x, y, z


iterating forwards
v
23

output = ["a", "b", "c"]

 v
23

mapping[3] = d, e, f

getting our put and mixxing we have 

output = ["ad", "ae", "af", ..., "cf"]


*/

class Solution {
public:

    void fill_mapping(unordered_map<int, vector<string>>& mapping) {
        mapping[2] = {"a", "b", "c"};
        mapping[3] = {"d", "e", "f"};
        mapping[4] = {"g", "h", "i"};
        mapping[5] = {"j", "k", "l"};
        mapping[6] = {"m", "n", "o"};
        mapping[7] = {"p", "q", "r", "s"};
        mapping[8] = {"t", "u", "v"};
        mapping[9] = {"w", "x", "y", "z"};
    }

    vector<string> compute_combinations(const vector<string>& s1, const vector<string>& s2) {
        vector<string> computed_combination;
        computed_combination.reserve(256);
        for (const string& str : s1) {
            for (const string& character : s2) {
                computed_combination.push_back(str + character);
            }
        }
        return computed_combination;
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
 
        unordered_map<int, vector<string>> mapping;
        mapping.reserve(9);
        fill_mapping(mapping);
        
        vector<string> strings {""};

        for (size_t i=0; i<digits.size(); ++i) {
            int key = digits[i]-'0';
            strings = compute_combinations(strings, mapping[key]);
        }

        return strings;
    }
};
