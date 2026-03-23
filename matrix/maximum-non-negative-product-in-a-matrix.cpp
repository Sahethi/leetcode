class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //dp should have maxProd and minProd
        vector<vector<pair<long long, long long>>> dp(m, vector<pair<long long, long long>> (n));
        dp[0][0] = {grid[0][0], grid[0][0]};

        for(int i=1; i<n; i++){
            long long val = grid[0][i];
            dp[0][i] = {dp[0][i-1].first * val, dp[0][i-1].second * val};
        }

        for(int j=1; j<m; j++){
            long long val = grid[j][0];
            dp[j][0] = {dp[j-1][0].first * val, dp[j-1][0].second * val};
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                long long val = grid[i][j];

                vector<long long> candidates = {
                    dp[i-1][j].first * val,
                    dp[i-1][j].second * val,
                    dp[i][j-1].first * val,
                    dp[i][j-1].second * val
                };

                long long maxEl = *max_element(candidates.begin(), candidates.end());
                long long minEl = *min_element(candidates.begin(), candidates.end());
                dp[i][j] = {maxEl, minEl};
            }
        }

        long long result = dp[m-1][n-1].first;

        if(result >= 0) return result;
        return -1;
    }
};