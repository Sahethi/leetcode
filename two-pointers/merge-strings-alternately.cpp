class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int len1 = word1.size();
        int len2 = word2.size();
        int n;
        if(len1 > len2){
            n = len2;
        }else{
            n = len1;
        }
        n=min(len2, len1);
        string res = "";
        int i;
        for(i=0; i<n; i++){
            res += word1[i];
            res += word2[i];
        }

        if(len1 == len2) return res;
        if(n == len2) res += word1.substr(i);
        else res += word2.substr(i);

        return res;
    }
};