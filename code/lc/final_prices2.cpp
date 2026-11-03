class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        for (int i=0; i<prices.size(); i++) {
            int curr = prices[i];
            while (!st.empty() && curr <= prices[st.top()]) {
                prices[st.top()] -= curr;
                st.pop();
            }
            st.push(i);
        }
        return prices;
    }
};
