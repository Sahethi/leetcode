class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1Len = s1.length();
        int s2Len = s2.length();

        if(s1Len + s2Len != s3.length()) return false;

        vector<vector<bool>> dp(s1Len+1, vector<bool>(s2Len+1, false));
        dp[0][0] = true;

        for(int i=1; i<=s1Len; i++){
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        }

        for(int j=1; j<=s2Len; j++){
            dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
        }

        for(int i=1; i<=s1Len; i++){
            for(int j=1; j<=s2Len; j++){
                dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i+j-1])) || (dp[i][j-1] && (s2[j-1] == s3[i+j-1]));
            }
        }

        return dp[s1Len][s2Len];
    }
};