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

        // vector<vector<int>> levelIndexed;

        int depth = 0;

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

            if(depth % 2 == 0){
                for(int j=0; j<level.size(); j++){
                    if(level[j] % 2 == 0) return false;
                    else if(j > 0 && level[j-1] >= level[j]) return false;
                }
            }else{
                for(int j=0; j<level.size(); j++){
                    if(level[j] % 2 == 1) return false;
                    else if(j > 0 && level[j-1] <= level[j]) return false;
                }
            }
            depth++;

            // levelIndexed.push_back(level);
            
        }

        // for(int i=0; i<levelIndexed.size(); i++){
        //     if(i % 2 == 0){
        //         for(int j=0; j<levelIndexed[i].size(); j++){
        //             if(levelIndexed[i][j] % 2 == 0) return false;
        //             else if(j > 0 && levelIndexed[i][j-1] >= levelIndexed[i][j]) return false;
        //         }
        //     } else {
        //         for(int j=0; j<levelIndexed[i].size(); j++){
        //             if(levelIndexed[i][j] % 2 == 1) return false;
        //             else if(j > 0 && levelIndexed[i][j-1] <= levelIndexed[i][j]) return false;
        //         }
        //     }
        // }

        return true;
    }
};