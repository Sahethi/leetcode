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
    unordered_map<int, int> freq;
    int dfs(TreeNode* root){
        if(root == NULL) return 0;

        int sum = 0;
        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);
        sum = root->val + leftSum + rightSum;
        freq[sum]++;
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int maxFreq = 0;
        dfs(root);
        for(auto& sum : freq){
            maxFreq = max(maxFreq, sum.second);
        }
        vector<int> result;

        for(auto& sum : freq){
            if(sum.second == maxFreq){
                result.push_back(sum.first);
            }
        }

        return result;
    }  
};