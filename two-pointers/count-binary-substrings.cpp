class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0, prevGroup=0, currGroup=1;
        // vector<int> groups;

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