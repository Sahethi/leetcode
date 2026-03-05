class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int contentKids = 0;
        int j;
        for(int i=0; i<g.size(); i++){
            for(j=0; j<s.size(); j++){
                if(s[j] >= g[i]){
                    contentKids++;
                    break;
                }
            }
            if(j == s.size() && contentKids!=0) break;
        }

        return contentKids;
    }
};