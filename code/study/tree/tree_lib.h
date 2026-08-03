#ifndef TREE_LIB_H
#define TREE_LIB_H

#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x);
};

// Traversals
void preOrder(TreeNode* root, std::vector<int>& result);
void inOrder(TreeNode* root, std::vector<int>& result);
void postOrder(TreeNode* root, std::vector<int>& result);

// BST Search
TreeNode* searchBST(TreeNode* root, int val);

// Invert Tree
TreeNode* invertTree(TreeNode* root);

#endif // TREE_LIB_H
