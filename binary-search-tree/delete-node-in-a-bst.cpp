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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root) return NULL;

        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }else{
            if(!root->left) return root->right;
            if(!root->right) return root->left;

            //temp has the largest val in left subtree
            TreeNode* temp = root->left;
            while(temp->right){
                temp = temp->right;
            }

            //replaced the root with the largest value in left subtree
            root->val = temp->val;
            //we have delete the duplicate
            root->left = deleteNode(root->left, temp->val);
        }

        return root;
    }
};