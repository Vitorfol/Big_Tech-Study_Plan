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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
             if (root == nullptr) return {};

        /*
        01 1
        02 2
        03 4
        04 8
        05 16
        06 32
        07 64
        08 128
        09 256
        10 512
        11 1024
        12 2048
        5. At most 2 thousand nodes in the tree
        */

        vector<vector<int>> response;
        int max_levels = 11;
        response.reserve(max_levels);
        queue<TreeNode*> to_process;

        to_process.push(root);

        vector<int> current_vector;

        /* 
        n = number of nodes
        time complexity:  O(n)
        */

        while (!to_process.empty()) {
            size_t level = to_process.size();
            
            for (size_t i=0; i<level; ++i) {
                TreeNode* front = to_process.front();
                to_process.pop();

                if (front->left != nullptr) to_process.push(front->left);
                if (front->right != nullptr) to_process.push(front->right);
                current_vector.push_back(front->val);
            }

            response.push_back(current_vector);
            current_vector.clear();
        }
        reverse(response.begin(), response.end());  
        return response;
    }
};
