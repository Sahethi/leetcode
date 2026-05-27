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
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    void inorder(TreeNode* root){
        if(root == NULL) return;

        TreeNode* curr = root;

        inorder(root->left);
        if(prev && prev->val > curr->val){
            if(first == nullptr){ //only do this for the first time
                first = prev;
            }
            second = curr;
        }
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
};