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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, long long>> q;
        if (!root) return 0;
        q.push({root, 0});
        int maxWidth = 0;


        while(!q.empty()){

            int size = q.size();
            maxWidth = max(maxWidth, (int)(q.back().second - q.front().second +1));
            long long minPos = q.front().second;

            for(int i=0; i<size; i++){
                auto [node, pos] = q.front();
                q.pop();
                pos -= minPos; //normalization
                long long leftPos = 2 * pos + 1;
                long long rightPos = 2 * pos + 2;

                if(node->left){
                    q.push({node->left, leftPos});
                }
                
                if(node->right){
                    q.push({node->right, rightPos});
                }
            }

        }
        return maxWidth;

    }
};