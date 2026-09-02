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
    int secondMinGlobal = INT_MAX;
private:
    int dfs(TreeNode* root, int minimum){
        if(root == NULL) return -1;

        if(root->val > minimum) return root->val;

        int left = dfs(root->left, minimum);
        int right = dfs(root->right, minimum);

        if(left == -1 && right == -1) return -1;

        if(left == -1) return right;
        if(right == -1) return left;

        return min(left, right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        return dfs(root, root->val);
    }
};