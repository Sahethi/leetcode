/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void buildParent(TreeNode* node, TreeNode* par){
        if(!node) return;

        parent[node] = par;
        buildParent(node->left, node);
        buildParent(node->right, node);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParent(root, NULL);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);
        int distance = 0;

        while(!q.empty() && distance < k){
            int size = q.size();

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                for(TreeNode* next : {node->left, node->right, parent[node]}){
                    if(next && !visited.count(next)){
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            distance++;
        }

        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};