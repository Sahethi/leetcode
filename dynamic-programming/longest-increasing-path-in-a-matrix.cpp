class Solution {
private:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(dp[i][j] != -1) return dp[i][j];
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 1;
        for(auto& [dx, dy] : dirs){
            int ni = dx + i;
            int nj = dy + j;

            if(ni >= 0 && nj >= 0 && ni < m && nj < n &&
                matrix[ni][nj] > matrix[i][j]){

                ans = max(ans, 1+ dfs(ni, nj, matrix, dp));
            }
        }

        return dp[i][j] = ans;

    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                res = max(res, dfs(i, j, matrix, dp, n, m));
            }
        }

        return res;
    }
};