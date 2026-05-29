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
    unordered_map<int, int> count;
    count[0] = 1; 
    int count = 0;
    void dfs(TreeNode* root, int targetSum){
        if(root == NULL) return;

        /**
        -3 + 11 = 8 
        8 + 3 = 11 - 11 = 0
        **/
        prefixSum += root->val;
        if(count[prefixSUm - targetSum] > 0){
            count += count[prefixSum - targetSum];
        }
        count[prefixSum]++;

        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        

    }
    int pathSum(TreeNode* root, int targetSum) {
        // so im thinking
        // discover tree paths -> array subarray sum

        dfs(root, targetSum);
        return count;
    }
};