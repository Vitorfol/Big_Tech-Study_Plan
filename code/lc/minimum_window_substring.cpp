class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> target_count(128, 0);
        int required = 0;

        for (char c : t) {
            if (target_count[c] == 0) required++;
            target_count[c]++;
        }

        vector<int> window_count(128, 0);
        int formed = 0;
        int left = 0;
        
        int min_len = INT_MAX;
        int best_left = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            char c = s[right];
            window_count[c]++;

            if (target_count[c] > 0 && window_count[c] == target_count[c]) {
                formed++;
            }

            while (formed == required) {
                int current_len = right - left + 1;
                if (current_len < min_len) {
                    min_len = current_len;
                    best_left = left;
                }

                char left_char = s[left];
                window_count[left_char]--;

                if (target_count[left_char] > 0 && window_count[left_char] < target_count[left_char]) {
                    formed--;
                }
                left++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(best_left, min_len);
    }
};
