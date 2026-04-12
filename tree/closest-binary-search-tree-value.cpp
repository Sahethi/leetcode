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
    int closestValue(TreeNode* root, double target) {
        int ans = root->val;

        while(root != NULL){

            double currDiff = abs(root->val - target);
            double ansDiff = abs(ans - target);


            if(abs(root->val - target) < abs(ans - target) 
            || currDiff == ansDiff && root->val < ans){
                ans = root->val;
            }else{
                if(target < root->val){
                    //move left
                    root = root->left;
                }else{
                    root = root->right;
                }
            }
        }

        return ans;

    }
};