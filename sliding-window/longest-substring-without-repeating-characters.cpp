class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //basically we have to keep a track on where did i track this last characters

        unordered_map<char, int> lastSeen;

        int left = 0, maxLen = 0;

        for(int i=0; i<s.length(); i++){

            //bascially its not present
            if(lastSeen.find(s[i]) != lastSeen.end()){
                //basically update the left 
                left = max(left, lastSeen[s[i]] + 1);
            }   

            lastSeen[s[i]] = i;
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};