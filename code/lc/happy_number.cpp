class Solution {
public:

    int replace(int number) {
        int result = 0;
        while (number > 0) {
            int digit = number % 10;
            result += digit * digit;
            number /= 10;
        }
        return result;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = replace(n);

        while (fast != 1 && slow != fast) {
            slow = replace(slow);
            fast = replace(replace(fast));
        }
         return fast==1;
    }
};
