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
    int totalTilt = 0;
    int dfs(TreeNode* node){
        if(node == NULL) return 0;

        int leftSum = 0, rightSum = 0;
        leftSum = dfs(node->left);
        rightSum = dfs(node->right);

        totalTilt += abs(leftSum - rightSum);

        return node->val + leftSum + rightSum;
    }
public:
    int findTilt(TreeNode* root) {
        //we need to return the sum of all the tilts
        //tilt = |sum of all nodes in right subtree - sum of all nodes in left subtree|
        dfs(root);
        return totalTilt;
    }
};