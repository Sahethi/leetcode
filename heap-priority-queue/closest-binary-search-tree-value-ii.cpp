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
    void inorder(TreeNode* root, vector<int>& arr){
        if(!root) return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        //this is like inorder traversal. + sliding window or binary search
        vector<int> arr;
        inorder(root, arr);

        //binary search
        int left = 0;
        int right = arr.size()-1;

        while(left < right){
            int mid = left + (right - left)/2;

            if(abs(arr[mid] - target) > abs(arr[mid+k] - target)){
                left = mid+1;
            }else{
                right = mid;
            }
        }

        return vector<int>(arr.begin()+left, arr.begin()+left+k);

        //sliding window
        // int left = 0;

        // while(left + k < arr.size()){
        //     if(abs(arr[left] - target) > abs(arr[left + k] - target)){
        //         left++;
        //     }else break;
        // }

        // vector<int> result;
        // for(int i=left; i<left+k; i++){
        //     result.push_back(arr[i]);
        // }

        // return result;
    }
};