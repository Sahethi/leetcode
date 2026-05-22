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
    bool dfs(TreeNode* root, int target, int sum){
        if(root == NULL) return false;

        sum += root->val;

        if(sum == target && root->left == NULL && root->right == NULL) return true;

        return dfs(root->left, target, sum) || dfs(root->right, target, sum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return dfs(root, targetSum, sum);
    }
};