#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1;
        vector<int> answer(nums.size(), 1);
        for (int i=0; i<nums.size(); i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        int sufix = 1;
        for (int i=nums.size()-1; i >= 0; i--) {
            answer[i] *= sufix;
            sufix *= nums[i];
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
