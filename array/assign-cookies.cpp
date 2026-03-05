class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int contentKids = 0;
        for(int i=0; i<g.size(); i++){
            for(int j=0; j<s.size(); j++){
                if(s[j] >= g[i]){
                    contentKids++;
                    break;
                }
            }
        }

        return contentKids;
    }
};