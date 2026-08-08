/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == nullptr) return nullptr;

        int curr = root->val;
        bool currHigherP = curr > p->val;
        bool currHigherQ = curr > q->val;

        if (curr == p->val || curr == q->val) return root;

        bool found = currHigherP ^ currHigherQ;

        if (found) return root; 

        if (p->val > root->val) return lowestCommonAncestor(root->right, p, q);
        return lowestCommonAncestor(root->left, p, q);
    }
};
