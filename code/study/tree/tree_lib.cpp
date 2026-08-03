#include "tree_lib.h"

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

void preOrder(TreeNode* root, std::vector<int>& result) {
    if (!root) return;
    result.push_back(root->val);
    preOrder(root->left, result);
    preOrder(root->right, result);
}

void inOrder(TreeNode* root, std::vector<int>& result) {
    if (!root) return;
    inOrder(root->left, result);
    result.push_back(root->val);
    inOrder(root->right, result);
}

void postOrder(TreeNode* root, std::vector<int>& result) {
    if (!root) return;
    postOrder(root->left, result);
    postOrder(root->right, result);
    result.push_back(root->val);
}

TreeNode* searchBST(TreeNode* root, int val) {
    TreeNode* curr = root;
    while (curr != nullptr) {
        if (val == curr->val) {
            return curr;
        } else if (val < curr->val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return nullptr;
}

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}
