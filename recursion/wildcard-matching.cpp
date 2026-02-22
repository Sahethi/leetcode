class Solution {
public:
    vector<vector<int>> memo;
    bool dfs(int i, int j, string& s, string& p){
        if(j == p.size()){
            return i == s.size();
        }

        if(memo[i][j] != -1){
            return memo[i][j];
        }
        
        bool ans=false;
        if(p[j] == '*'){
            ans = dfs(i, j+1, s, p) || (i < s.size() && dfs(i+1, j, s, p));
        }else{
            bool firstMatch = (i < s.size() &&
                          (s[i] == p[j] || p[j] == '?'));

            ans = firstMatch && dfs(i+1, j+1, s, p);
        }
        memo[i][j] = ans;
        return ans;
    }
    bool isMatch(string s, string p) {
        memo.assign(s.size() + 1, vector<int>(p.size()+1, -1));
        return dfs(0, 0, s, p);
    }
};
