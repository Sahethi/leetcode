class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int contentKids = 0;
        int j;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for(int i=0; i<g.size(); i++){
            for(j=i; j<s.size(); j++){
                if(s[j] >= g[i]){
                    contentKids++;
                    break;
                }
            }
        }

        return contentKids;
    }
};