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
    int prefixSum = 0;
    unordered_map<int, long long> count;
    
    int ans = 0;
    void dfs(TreeNode* root, int targetSum){
        if(root == NULL) return;

        /**
        -3 + 11 = 8 
        8 + 3 = 11 - 11 = 0
        **/
        prefixSum += root->val;
        if(count[prefixSum - targetSum] > 0){
            ans += count[prefixSum - targetSum];
        }
        count[prefixSum]++;

        dfs(root->left, targetSum);
        dfs(root->right, targetSum);

        count[prefixSum]--;
        prefixSum -= root->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        // so im thinking
        // discover tree paths -> array subarray sum
        count[0] = 1; 
        dfs(root, targetSum);
        return ans;
    }
};