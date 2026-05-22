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
    pair<int, int> dfs(TreeNode* root){
        if(root == NULL) return {0,0};
        int skip, rob;


        auto [left_rob, left_skip] = dfs(root->left);
        auto [right_rob, right_skip] = dfs(root->right);

        skip = max(left_rob, left_skip) + max(right_rob, right_skip);
        rob = root->val + left_skip + right_skip;

        return {rob, skip};
    }
    int rob(TreeNode* root) {
        //if i skip the current node so i need to rob its children 
        // skip = max(left_rob, left_skip) + max(right_rob, right_skip)

        //if i rob the current node then i need to skip the children
        // rob = node.val + left_skip + right_skip

        auto [rob, skip] = dfs(root);
        return max(rob, skip);
    }
};