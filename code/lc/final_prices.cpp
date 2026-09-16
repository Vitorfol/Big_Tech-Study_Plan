#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st; 
        for (int i=0; i<prices.size(); i++) {
            //cout << "current: " << prices[i]; 
            while(!st.empty() && prices[i] <= prices[st.top()]) {
                //cout << "top: " << prices[st.top()] << " ";
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
            //cout << endl;
        }

        return prices;
    }
};

int main() {
    int n; cin >> n;
    vector<int> prices(n);
    for (int i=0; i<n; i++) cin >> prices[i];
    Solution solution;
    prices = solution.finalPrices(prices);
    for (int price : prices) cout << price << " ";
}