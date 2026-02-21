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

 //in this version we gotta do sorting as well
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};
        map<int, map<int, multiset<int>>> mp;
        queue<tuple<TreeNode*, int, int>> q;

        q.push({root, 0, 0}); // node, row, col

        while(!q.empty()){
            auto [node, row, col] = q.front();
            q.pop();

            mp[col][row].insert(node->val);

            if(node->left)
                q.push({node->left, row + 1, col - 1});
            if(node->right)
                q.push({node->right, row + 1, col + 1});
        }

        vector<vector<int>> result;

        for(auto& [col, rows] : mp){
            vector<int> column;
            for(auto& [row, values] : rows){
                column.insert(column.end(), values.begin(), values.end());
            }
            result.push_back(column);
        }

        return result;
    }
};