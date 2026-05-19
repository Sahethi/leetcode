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

        vector<vector<int>> levelIndexed;
        while(!q.empty()){
            int n = q.size();
            vector<int> level;

            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            levelIndexed.push_back(level);
            
        }

        for(int i=0; i<levelIndexed.size(); i++){
            if(i % 2 == 0){
                for(int j=0; j<levelIndexed[i].size(); j++){
                    if(levelIndexed[i][j] % 2 == 0) return false;
                    else if(j > 0 && levelIndexed[i][j-1] >= levelIndexed[i][j]) return false;
                }
            } else {
                for(int j=0; j<levelIndexed[i].size(); j++){
                    if(levelIndexed[i][j] % 2 == 1) return false;
                    else if(j > 0 && levelIndexed[i][j-1] <= levelIndexed[i][j]) return false;
                }
            }
        }

        return true;
    }
};