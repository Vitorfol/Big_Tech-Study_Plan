class Solution {
public:
    bool hasCycle(vector<vector<int>>& adj, vector<int>& state, int curr) {
        state[curr] = 1;
        
        for (int neighbor : adj[curr]) {
            if (state[neighbor] == 0 && hasCycle(adj, state, neighbor)) {
                return true;
            } else if (state[neighbor] == 1) {
                return true;
            }
        }

        state[curr] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (size_t i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];
            adj[course].push_back(pre);
        }

        vector<int> memory(numCourses, 0);

        for (size_t i = 0; i < numCourses; i++) {
            if (memory[i] != 2 && hasCycle(adj, memory, i)) {
                return false;
            }
        }

        return true;
    }
};
