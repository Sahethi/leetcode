class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, left = 0;
        long long product = 1;
        if (k <= 1) return 0;
        
        for(int right = 0; right < nums.size(); right++){
            product *= nums[right];
            while(product >= k){
                product /= nums[left];
                left++;
            }
            //total elements inside the array are total valid subarrays
            ans += right - left + 1;
        }
        return ans;
    }
};