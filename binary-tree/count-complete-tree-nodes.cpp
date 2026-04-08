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
    int countNodes(TreeNode* root) {
        //for a perfect binary tree if h is the height
        //2^h-1 is the total amt of nodes if left and right height is same

        //naive approach

        return root != NULL ? 1 + countNodes(root->right) + countNodes(root->left) : 0;
    }
};