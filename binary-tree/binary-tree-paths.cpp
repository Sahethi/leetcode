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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string ans="";
        path(root, result, ans);

        return result;
    }

    void path(TreeNode* root, vector<string>& result, string ans){
        if(root == NULL) return;
        ans += to_string(root->val);


        if(root->left == NULL && root->right == NULL){
            result.push_back(ans);
            return;
        }
        ans += "->";
        path(root->left, result, ans);
        path(root->right, result, ans);

    }
};