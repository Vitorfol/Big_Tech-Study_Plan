#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int nums_size = nums.size();
        int zero_counter = 0;
        vector<int> answer(nums_size);

        for (int i=0; i<nums_size; i++) {
            if (nums[i] == 0) {
                zero_counter++;
                continue;
            }
            product *= nums[i];
        }

        if (zero_counter >= 2) {
            fill(answer.begin(), answer.end(), 0);
            return answer;
        }

        if (zero_counter == 1) {
            for (int i=0; i<nums_size; i++) {
                if (nums[i] != 0) answer[i] = 0;
                else answer[i] = product; 
            }
            return answer;
        }

        for (int i=0; i<nums_size; i++) {
            answer[i] = product / nums[i];
        }

        return answer;
    }
};

int main() {
    int n;
    cout << "Digite a quantidade de elementos: ";
    if (!(cin >> n) || n <= 0) return 0;

    vector<int> nums(n);
    cout << "Digite os " << n << " elementos separados por espaco: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    vector<int> result = solution.productExceptSelf(nums);

    cout << "Resultado: [ ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << "]" << endl;

    return 0;
}
