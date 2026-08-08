class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        while (root != nullptr) {

            // Os dois estão à esquerda
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }

            // Os dois estão à direita
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }

            // Estão em lados diferentes, ou root é p/q
            else {
                return root;
            }
        }

        return nullptr;
    }
};
