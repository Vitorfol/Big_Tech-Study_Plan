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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> solution;
        vector<int> path;
        travel(root, solution, path);

        vector<string> result;
        for (const auto& p : solution) {
            string current = to_string(p[0]);
            for (size_t i = 1; i < p.size(); ++i) {
                current += "->" + to_string(p[i]);
            }
            result.push_back(current);
        }
        return result;
}

    void travel(TreeNode* root, vector<vector<int>>& solution, vector<int>& path) {

        if (root == NULL) return;

        path.push_back(root->val);

        if (root->left == NULL && root-> right == NULL) {
            solution.push_back(path);
            path.pop_back();
            return;
        }

        travel(root->left, solution, path);
        travel(root->right, solution, path);
        path.pop_back();
    }
};
