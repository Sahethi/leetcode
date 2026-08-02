class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int left = 0, right=0, maxLen = 0;
        unordered_map<char, int> lastSeen;
        int n = s.length();

        for(int i=0; i<n; i++){
            if(lastSeen.find(s[i]) != lastSeen.end()){
                left = max(left, lastSeen[s[i]] + 1); 
            }
            lastSeen[s[i]] = i;
            maxLen = max(maxLen, i - left +1);
        }
        return maxLen;
    }
};