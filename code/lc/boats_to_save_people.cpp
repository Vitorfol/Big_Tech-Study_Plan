class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        size_t left = 0;
        size_t right = people.size()-1;
        int k = 0;

        sort(people.begin(), people.end());

        while (left < right) {
            int left_value = people[left];
            int right_value = people[right];

            if (left_value + right_value <= limit) ++left;
            --right;
            ++k;
        }

        if (left == right) ++k;

        return k;
    }
};
