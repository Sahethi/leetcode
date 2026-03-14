class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0;
        vector<int> groups;
        int prevGroup;
        int currGroup;
        for(int i=1; i<s.length()-1; i++){
            if(s[i] == s[i-1]){
                currGroup++;
            }else{
                prevGroup = currGroup;
                groups.push_back(prevGroup);
                currGroup = 1;
            }
        }

        return ans;
    }
};