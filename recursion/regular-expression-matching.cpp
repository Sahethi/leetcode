// class Solution {
// public:
//     bool isMatch(string s, string p) {
        
//         int n = s.size();
//         int m = p.size();

//         //2d dp table
//         // vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

//         bool dp[n+1][m+1];
//         memset(dp, false, sizeof(dp));

//         //base case for empty string
//         dp[0][0] = true;

//         //basically patterns that can shrink to empty string
//         for(int i=2; i<=m; i++){
//             if(p[i-1] == '*'){
//                 dp[0][i] = dp[0][i-2];
//             }
//         }


//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=m; j++){
//                 if(p[j-1] == s[i-1] || p[j-1] == '.'){
//                     dp[i][j] = dp[i-1][j-1];
//                 } else if(p[j-1] == '*'){
//                     //in case of zero occurences
//                     dp[i][j] = dp[i][j-2];

//                     if(s[i-1] == p[j-2] || p[j-2] == '.'){
//                         dp[i][j] = dp[i][j] || dp[i-1][j];

//                     }
//                 }
//             }
//         }

//         return dp[n][m];

//     }
// };

class Solution {
public:
    vector<vector<int>> memo;
    
    bool dfs(int i, int j, string &s, string &p) {
        if (j == p.size()) {
            return i == s.size();
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        bool firstMatch = (i < s.size() &&
                          s[i] == p[j]) || p[j] == '.';
        
        bool ans;
        
        if (j + 1 < p.size() && p[j + 1] == '*') {
            ans = dfs(i, j + 2, s, p) || 
                  (firstMatch && dfs(i + 1, j, s, p));
        } else {
            ans = firstMatch && dfs(i + 1, j + 1, s, p);
        }
        
        memo[i][j] = ans;
        return ans;
    }
    
    bool isMatch(string s, string p) {
        memo.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dfs(0, 0, s, p);
    }
};