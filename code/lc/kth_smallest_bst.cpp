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
    void findKthSmallerNode(TreeNode* root, int& current_k, int target_k, int& ans) {

        if (root == NULL) return;

        findKthSmallerNode(root->left, current_k, target_k, ans);

        if (current_k >= target_k) return;

        if (++current_k == target_k) {
            ans = root->val;
            return;
        }

        findKthSmallerNode(root->right, current_k, target_k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int current_k = 0;
        int answer = -1;
        findKthSmallerNode(root, current_k, k, answer);
        return answer;
    }
};
