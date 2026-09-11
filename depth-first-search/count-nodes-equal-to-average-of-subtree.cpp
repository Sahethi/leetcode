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
    int ans = 0;
    pair<int,int> dfs(TreeNode* root){
        if(root == NULL) return {0,0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int totalSum = 0, count = 0;
        totalSum += left.first + right.first + root->val;
        count += left.second + right.second + 1;

        if(root->val == totalSum/count){
            ans++;
        }

        return {totalSum, count};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};