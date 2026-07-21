class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
       string ans = "";
       int count = 0;

       for(int i=s.size()-1; i>=0; i--){
            if(s[i] == '-') continue;

            ans += toupper(s[i]);
            count++;
            
            if(count == k) {
                count = 0;
                ans += '-';
            }
       }

       if(!ans.empty() && ans[ans.size()-1] == '-'){
            ans.pop_back();
       }

       reverse(ans.begin(), ans.end());

       return ans;
    }
};