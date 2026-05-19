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
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL) return true;

        queue<TreeNode*> q;
        q.push(root);

        bool flag = true;
        while(!q.empty()){
            int n = q.size();
            int prev = flag ? INT_MIN : INT_MAX;

            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();

                if(flag){
                    if(node->val % 2 == 0 || node->val <= prev){
                        return false;
                    }
                }else{
                    if(node->val % 2 == 1 || node->val >= prev){
                        return false;
                    }
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
                prev = node->val;
            }  

            flag = !flag;
        }

        return true;
    }
};