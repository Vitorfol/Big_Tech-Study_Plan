/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, vector<Node*>& cloned) {
        if (node == nullptr) return nullptr;
        if (cloned[node->val]) return cloned[node->val];

        Node* cloned_node = new Node(node->val);
        cloned[node->val] = cloned_node;

        for (auto neighbor : node->neighbors) {
            Node* neighbor_cloned = dfs(neighbor, cloned);
            cloned_node->neighbors.push_back(neighbor_cloned);
        }

        return cloned_node;
    }

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return {};

        vector<Node*> cloned(101, nullptr);
        return dfs(node, cloned);
    }
};
