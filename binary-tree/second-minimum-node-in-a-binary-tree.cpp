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
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL) return -1;
        if(root->left != NULL && root->right != NULL)
            if(root->left->val == root->right->val) return -1;

        if(root->right == NULL && root->left != NULL) return root->left->val;
        if(root->right == NULL) return -1;
        return root->right->val;
    }
};