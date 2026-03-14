class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0;
        // vector<int> groups;
        int prevGroup=0;
        int currGroup=1;

        for(int i=1; i<s.length(); i++){
            if(s[i] == s[i-1]){
                currGroup++;
            }else{
                ans += min(prevGroup, currGroup);
                prevGroup = currGroup;
                currGroup = 1;
            }
        }

        ans += min(prevGroup, currGroup);
        
        return ans;
    }
};