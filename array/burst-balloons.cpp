class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //basically bursting the balloon i changes the way next choice is made
        //because the neighbors change hence this is a classic DP problem

        //think about the last baloon you have to burst rather than first
        //because bursting the first baloon changes the neighbors

        /*
        total coins =
        coins from left interval
        + coins from right interval
        + coins from bursting i last
        */

        //padding with 1 on both left and right
        vector<int> arr;
        arr.push_back(1);

        for(int n : nums)
            arr.push_back(n);

        arr.push_back(1);

        int m = arr.size();

        vector<vector<int>> dp(m, vector<int>(m, 0));

        for(int len=2; len<m; len++){
            for(int left = 0; left + len  < m; left++){
                int right = left + len;
                for(int i = left + 1; i<right; i++){
                    dp[left][right] = max(dp[left][right],
                        dp[left][i] + 
                        dp[i][right] + 
                        arr[left] * arr[i] * arr[right]);
                }
            }
        }
        return dp[0][m-1];
    }
};