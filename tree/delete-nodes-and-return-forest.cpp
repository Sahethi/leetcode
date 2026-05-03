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
    unordered_set<int> toDelete;
    vector<TreeNode*> forest;

    TreeNode* dfs(TreeNode* root, bool isRoot){
        if(!root) return NULL;

        bool deleted = toDelete.count(root->val);
        if(isRoot && !deleted){
            forest.push_back(root);
        }

        root->left = dfs(root->left, deleted);
        root->right = dfs(root->right, deleted);

        return deleted ? NULL : root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete){

        for(int i : to_delete){
            toDelete.insert(i);
        }

        dfs(root, true);
        return forest;
    }
};