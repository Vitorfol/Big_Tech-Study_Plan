// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int first_bad = INT_MAX;

        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (isBadVersion(mid)) {
                first_bad = min(first_bad, mid);
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }

        return first_bad;
    }
};
