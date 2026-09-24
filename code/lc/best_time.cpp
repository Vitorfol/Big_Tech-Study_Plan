#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_val = prices[0];

        for (int i=1; i<prices.size(); i++) {
            if (prices[i] < min_val) min_val = prices[i];
            else if (prices[i] - min_val > max_profit) max_profit = prices[i] - min_val;
        }

        return max_profit;
    }
};

int main() {

	Solution solution;
	int n; cin >> n;
	vector<int> prices;
	for (int i=0; i<n; i++) {
		int aux; cin >> aux;
		prices.push_back(aux);
	}

	cout << solution.maxProfit(prices);

}
