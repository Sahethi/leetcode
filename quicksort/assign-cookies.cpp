class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int contentKids = 0;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int childPtr = 0, cookiePtr=0;

        while(cookiePtr < s.size() && childPtr < g.size()){
            if(s[cookiePtr] >= g[childPtr]){
                contentKids++;
                childPtr++;
            }
            cookiePtr++;
        }

        return contentKids;
    }
};