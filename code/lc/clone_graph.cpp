class Solution {
public:
    unordered_map<Node*, Node*> clones;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr; 
        
        return dfs(node);
    }

    Node* dfs(Node* curr) {
        if (clones.find(curr) != clones.end()) {
            return clones[curr];
        }

        Node* copy = new Node(curr->val);
        clones[curr] = copy; 

        for (Node* neighbor : curr->neighbors) {
            copy->neighbors.push_back(dfs(neighbor));
        }

        return copy;
    }
};
