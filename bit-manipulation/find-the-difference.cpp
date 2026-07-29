class Solution {
public:
    char findTheDifference(string s, string t) {
        

        int k=0, j=0;
        //t always has extra letter

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        int n = s.size();
        int i;
        for(i=0; i<n; i++){
            if(s[k] == t[j]){
                k++;
                j++;
            }else{
                return t[j];
            }
        }

        if(i == n){
            return t[j];
        }
        return t[j];
    }
};