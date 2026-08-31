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
    int diameter = 0;
public:
    int dfs(TreeNode* root){
        if(root == NULL) return 0;

        int leftHeight = 0, rightHeight = 0, currDia = 0;
        leftHeight = dfs(root->left);
        rightHeight = dfs(root->right);
        currDia = leftHeight + rightHeight;

        diameter = max(diameter, currDia);

        return 1 + max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
};