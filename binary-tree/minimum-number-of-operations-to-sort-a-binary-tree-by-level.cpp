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
    int minSwaps(vector<int>& level){
        int n = level.size();
        vector<pair<int, int>> arr;

        for(int i=0; i<n; i++){
            arr.push_back({level[i], i});
        }

        sort(arr.begin(), arr.end());
        
        int swaps = 0;
        vector<bool> visited(n, false);

        for(int i=0; i<n; i++){
            
            int cycleSize = 0;
            int j = i;

            if(visited[i] || arr[i].second == i) continue;

            while(!visited[j]){
                visited[j] = true;
                j = arr[j].second;
                cycleSize++;
            }

            swaps += (cycleSize - 1);

        }

        return swaps;

    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);
        int totalSwaps = 0;

        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            totalSwaps += minSwaps(level);
        }
        
        return totalSwaps;
    }
};