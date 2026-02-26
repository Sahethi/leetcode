class Solution {
public:
    int knightDialer(int n) {
        const int MOD = 1e9 + 7;
        
        vector<long> dp(10, 1);  // length = 1
        
        for (int step = 2; step <= n; step++) {
            vector<long> newDp(10, 0);
            
            newDp[0] = (dp[4] + dp[6]) % MOD;
            newDp[1] = (dp[6] + dp[8]) % MOD;
            newDp[2] = (dp[7] + dp[9]) % MOD;
            newDp[3] = (dp[4] + dp[8]) % MOD;
            newDp[4] = (dp[0] + dp[3] + dp[9]) % MOD;
            newDp[5] = 0;
            newDp[6] = (dp[0] + dp[1] + dp[7]) % MOD;
            newDp[7] = (dp[2] + dp[6]) % MOD;
            newDp[8] = (dp[1] + dp[3]) % MOD;
            newDp[9] = (dp[2] + dp[4]) % MOD;
            
            dp = newDp;
        }
        
        long result = 0;
        for (int i = 0; i < 10; i++) {
            result = (result + dp[i]) % MOD;
        }
        
        return result;
    }
};