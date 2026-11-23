class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        queue<int> to_process;
        vector<int> min_dist(amount+1, -1);
        min_dist[amount] = 0;
        int dist = 1;

        to_process.push(amount);

        while (!to_process.empty()) {
            size_t size = to_process.size();

            for (size_t i=0; i<size; ++i) {
                int front = to_process.front();
                to_process.pop();
                for (int coin : coins) {
                    int remaining = front - coin;
                    if (remaining == 0) return dist;
                    if (remaining < 0 || min_dist[remaining] != -1) continue;
                    min_dist[remaining] = dist;
                    to_process.push(remaining);
                }
            }
            ++dist;
        }

        return -1;
    }
};
