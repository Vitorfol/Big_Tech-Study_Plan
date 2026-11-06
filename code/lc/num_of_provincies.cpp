class Solution {
public:

    void bfs(vector<vector<int>>& adj, vector<bool>& visited, size_t src) {
        queue<int> q;
        visited[src] = true;
        q.push(src);

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for (size_t i=0; i<adj[curr].size(); ++i) {
                if (adj[curr][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                } 
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = static_cast<int>(isConnected.size());
        vector<bool> visited(size, false);
        size_t num_provincies = 0;
        for (size_t i=0; i<isConnected.size(); ++i) {
            if (visited[i]) continue;
            bfs(isConnected, visited, i);
            ++num_provincies; 
        }
        return num_provincies;
    }
};
