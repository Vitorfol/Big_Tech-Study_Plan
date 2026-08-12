class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); 
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        } 

        vector<int> visited(numCourses, 0);
        for (int i=0; i<numCourses; i++) {
            bool find_cycle = cycle_dfs(adj, i, visited);
            if (find_cycle) return false;
        }

        return true;
    }

    bool cycle_dfs (vector<vector<int>>& preRequisites, int current, vector<int>& visited) {
        if (visited[current] == 1) return true;
        if (visited[current] == 2) return false;
        visited[current] = 1;
        
        for (int neighbor : preRequisites[current]) {
            if (cycle_dfs(preRequisites, neighbor, visited)) return true;
        }
        visited[current] = 2;
        return false;
    }
};
