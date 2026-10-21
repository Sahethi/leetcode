class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        
        int len = nums.size();
        int midEl = nums[len/2];
        int count = 0;
        for(int n : nums){
            if(n == midEl) count++;
        }

        if(count >= 2) return false; 
        return true;
    }
};