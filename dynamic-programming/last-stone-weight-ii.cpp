class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int sum = 0;
        for(int stone : stones){
            sum += stone;
        }      
        int n = stones.size();
        int target = sum / 2;
        vector<bool> dp(target+1, false);
        dp[0] = true;

        for(int i=0; i<n; i++){
            for(int j=target; j>=stones[i]; j--){
                dp[j] = dp[j] || dp[j-stones[i]];
            }
        }

        for(int j=target; j>=0; j--){
            if(dp[j]){
                return sum - 2 * j;
            }
        }

        return 0;

    }
};