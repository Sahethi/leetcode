class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();

        vector<vector<int>> dp(maxTime + 1, vector<int>(n, INT_MAX));
        dp[0][0] = passingFees[0];

        for(int i=1; i<=maxTime; i++){
            for(auto& edge : edges){
                int u = edge[0];
                int v = edge[1];
                int t = edge[2];

                if(i >= t){
                    if(dp[i-t][u] != INT_MAX){
                        dp[i][v] = min(dp[i][v], dp[i-t][u] + passingFees[v]);
                    }
                    if(dp[i-t][v] != INT_MAX){
                        dp[i][u] = min(dp[i][u], dp[i-t][v] + passingFees[u]);
                    }
                }
            }
        }

        int ans = INT_MAX;
        for(int i=0; i<=maxTime; i++){
            ans = min(ans, dp[i][n-1]);
        }

        return ans == INT_MAX ? -1 : ans;

    }
};