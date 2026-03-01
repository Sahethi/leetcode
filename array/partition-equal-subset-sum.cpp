class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //Let dp[i][s] = can we form sum s using first i numbers?
        int n = nums.size();
        int total = 0;
        int target = 0;
        vector<bool> dp(target+1, false);
        dp[0] = true;

        for(int i=0; i<n; i++)
            total += nums[i];

        if(total % 2 == 0){
            target = total/2;
            for(int i=0; i<n; i++){
                for(int s=target; s>=nums[i]; s--){
                    dp[s] = dp[s] || dp[s - nums[i]];
                }
            }
        }else{
            return false;
        }
        
        return dp[target];
    }
};