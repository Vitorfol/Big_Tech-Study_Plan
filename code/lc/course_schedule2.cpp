class Solution {
public:
    bool hasSolution(const vector<vector<int>>& adj, vector<int>& state, int current, vector<int>& order) {
        if (state[current] == 2) return true;
        if (state[current] == 1) return false;

        state[current] = 1;

        for (int neighbor : adj[current]) {
            if(!hasSolution(adj, state, neighbor, order)) return false;
        }

        state[current] = 2;
        order.push_back(current);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (size_t i=0; i<prerequisites.size(); ++i) {
            int course = prerequisites[i][0];
            int prerequisite = prerequisites[i][1];
            adj[course].push_back(prerequisite);
        }

        vector<int> states(numCourses, 0);
        vector<int> solution;
        
        for (size_t j=0; j<numCourses; ++j) {
            if(!hasSolution(adj, states, j, solution)) return vector<int>();
        }

        return solution;
    }
};
