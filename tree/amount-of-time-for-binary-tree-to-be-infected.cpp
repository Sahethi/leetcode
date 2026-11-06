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
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* startNode = NULL;

    void buildParent(TreeNode* node, TreeNode* par, int start){
        if(!node) return;

        parent[node] = par;

        if(node->val == start){
            startNode = node;
        }

        buildParent(node->left, node, start);
        buildParent(node->right, node, start);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        buildParent(root, NULL, start);

        int minutes = 0;

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        
        q.push(startNode);
        visited.insert(startNode);

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                for(TreeNode* next : {node->left, node->right, parent[node]}){
                    if(next && !visited.count(next)){
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }

            minutes++;
        }

        return minutes-1;
    }
};