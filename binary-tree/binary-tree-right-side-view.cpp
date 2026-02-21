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
private:
    //BFS Solution
    vector<int> bfs(TreeNode* root){
        vector<int> result;
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(i == size-1){
                    result.push_back(curr->val);
                }

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return result;
    }
    //DFS solution
    void dfs(TreeNode* root, int depth, vector<int>& result){
        if(!root) return;

        if(depth == result.size()){
            result.push_back(root->val);
        }

        if(root->right) dfs(root->right, depth+1, result);
        if(root->left) dfs(root->left, depth+1, result);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        // vector<int> result;
        // dfs(root, 0, result);
        // return result;

        return bfs(root);
    }
};