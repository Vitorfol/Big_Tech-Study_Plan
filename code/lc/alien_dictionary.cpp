class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int size = order.size();
        unordered_map<char, int> order_map;
        order_map.reserve(size + 1);
        int pos = 1;

        for (char character : order) {
            order_map[character] = pos;
            pos++;
        }
        order_map['\0'] = 0; 

        for (int i = 0; i < (int)words.size() - 1; i++) {
            const string curr = words[i];
            const string next = words[i + 1];
            int curr_size = curr.size();
            int next_size = next.size();

            for (int j = 0; j < curr_size; j++) {
                char c1 = curr[j];
                char c2 = (j < next_size) ? next[j] : '\0';

                if (order_map[c1] > order_map[c2]) return false; 
                if (order_map[c1] < order_map[c2]) break; 
            }
        }

        return true; 
    }
};
