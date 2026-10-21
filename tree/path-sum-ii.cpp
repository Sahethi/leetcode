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
    vector<vector<int>> ans;

    void dfs(TreeNode* root, int remainingSum, vector<int>& result){
        if(root == NULL) return;

        remainingSum -= root->val;
        
        result.push_back(root->val);

        if(root->left == NULL && root->right == NULL && remainingSum == 0)
            ans.push_back(result);

        dfs(root->left, remainingSum, result);
        dfs(root->right, remainingSum, result);

        result.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> result;
        dfs(root, targetSum, result);
        return ans;
    }
};