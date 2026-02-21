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
    int count = 0;
    void traversal(TreeNode* root, int maxSoFar){
        if(!root) return;

        if(root->val >= maxSoFar){
            count++;
        }

        maxSoFar = max(maxSoFar, root->val);
        traversal(root->left, maxSoFar);
        traversal(root->right, maxSoFar);
    }
public:
    int goodNodes(TreeNode* root) {
        traversal(root, root->val);
        return count;

    }
};