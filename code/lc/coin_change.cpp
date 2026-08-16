class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (coins.size() == 0) return -1;

        int num_coins = coins.size();

        unordered_map<int, vector<int>> memo;
        unordered_set<int> visited;
        queue<int> fila;

        fila.push(amount);
        int high = 0;

        while (!fila.empty()) {
            int level_size = fila.size();

            while (level_size--) {
                int front = fila.front();

                if (front == 0) return high;
                fila.pop();
                if (front < 0) continue;

                if (!memo.contains(front)) {
                    vector<int> aux(num_coins);

                    for (int i = 0; i < num_coins; i++) {
                        aux[i] = front - coins[i];
                    }

                    memo[front] = aux;
                }

                for (int i = 0; i < num_coins; i++) {
                    int candidate = memo[front][i];
                    if (candidate >= 0 && !visited.contains(candidate)) {
                        visited.insert(candidate);
                        fila.push(memo[front][i]);
                    }
                }
            }
            high++;
        }

        return -1;
    }
};
