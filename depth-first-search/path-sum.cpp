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
    bool dfs(TreeNode* node, int target, int sum){
        if(node == NULL) return false;
        sum += node->val;
        
        if(sum == target && node->left == NULL && node->right == NULL) return true;
        return dfs(node->left, target, sum) || dfs(node->right, target, sum);

    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;  
        return dfs(root, targetSum, sum);
    }
};