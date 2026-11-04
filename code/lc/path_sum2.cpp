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


 /* 

    Idea:
    Test all dfs paths from root to leaf, saving its values and a current sum. If when we reach a leaf the current sum is equal to our target, we found a possible solution.

    auxiliar function: void dfs(TreeNode* root, vector<vector<int>>& solutions, vector<int> current_values, int current_sum, int target)


 */
class Solution {
public:

    void dfs(TreeNode* root, vector<vector<int>>& solutions, vector<int>& current_values, int current_sum, int target) {

        if (root == NULL) return;

        current_sum += root->val;
        current_values.push_back(root->val);
        
        if (root->left == NULL && root->right == NULL) {
            if (current_sum == target) solutions.push_back(current_values);
            current_values.pop_back();
            return;
        }

        TreeNode* left = root->left;
        TreeNode* right = root->right;
        dfs(left, solutions, current_values, current_sum, target);
        dfs(right, solutions, current_values, current_sum, target);
        current_values.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> solutions;
        vector<int> current_values;
        dfs(root, solutions, current_values, 0, targetSum);
        return solutions;
    }
};
