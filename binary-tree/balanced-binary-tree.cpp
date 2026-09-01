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
    private: 
        int diff = 0;
    public:
        int dfs(TreeNode* root){
            if(root == NULL) return 0;

            int leftHeight = dfs(root->left);
            int rightHeight = dfs(root->right);
            diff = abs(leftHeight - rightHeight);
            return (1 + max(leftHeight, rightHeight));
        }
        bool isBalanced(TreeNode* root) {
            dfs(root);
            if(diff > 1) return false;
            return true;
        }
};
    