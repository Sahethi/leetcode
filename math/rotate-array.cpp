class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> temp(n);
        for(int i=0; i<n; i++){
            int new_index = (i+k) % n;
            temp[new_index] = nums[i];
        }
        nums = temp;
    }
};