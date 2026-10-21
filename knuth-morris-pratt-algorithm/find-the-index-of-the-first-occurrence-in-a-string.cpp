class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int window = needle.length();
        int n = haystack.length();
        int start = 0;

        for(int i=0; i<n; i++){
            if(haystack[i] == needle[start]){
                start++;
            }else{
                i = i - start;
                start = 0;
            }

            if(start == window){
                return i - window + 1;
            }
        }

        return -1;
    }
};