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
    int ans = 0;
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int left = 0, right = 0;
        int leftSide = dfs(root->left);
        int rightSide = dfs(root->right);

        if(root->left && root->left->val == root->val){
            left++;
        }else{
            left = 0;
        }

        if(root->right && root->right->val == root->val){
            right++;
        }else{
            right = 0;
        }

        ans = max(ans, left+right);

        return max(left, right);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};