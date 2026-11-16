/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void travel(TreeNode* root, vector<vector<int>>& solution) {

        if (root == nullptr) return;

        queue<TreeNode*> fila;
        fila.push(root);

        vector<int> current_solution;

        while (!fila.empty()) {

            int size = static_cast<int>(fila.size());

            for (size_t i=0; i<size; ++i) {
                TreeNode* front = fila.front();
                fila.pop();
                current_solution.push_back(front->val);
                if (front->left != nullptr) fila.push(front->left);
                if (front->right != nullptr) fila.push(front->right);
            }

            solution.push_back(current_solution);
            current_solution.clear();    

        }

    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> solution;
        travel(root, solution);
        return solution;
    }
};
