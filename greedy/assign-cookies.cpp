class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int contentKids = 0;
        int j;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int childPtr = 0, cookiePtr=0;
        for(int i=0; i<g.size(); i++){
            for(j=0; j<s.size(); j++){
                if(cookiePtr < s.size() && childPtr < g.size() && s[cookiePtr] >= g[childPtr]){
                    contentKids++;
                    childPtr++;
                    cookiePtr++;
                    break;
                }else{
                    childPtr++;
                }
            }
        }

        return contentKids;
    }
};