class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int mul = 0;
        if(nums[0] < 0 && nums[1] < 0){
            mul = nums[0] * nums[1];
        }
        int negProd = mul * nums[n-1];

        return max(negProd, nums[n-1] * nums[n-2] * nums[n-3]);
    }
};