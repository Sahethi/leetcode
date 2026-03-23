class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right=0, maxLen = 0;
        unordered_map<char, int> freq;

        int n = s.length();

        for(right = 0; right < n; right++){
            if(freq[s[right]] == 0){
                freq[s[right]]++;
                
            }else{
                while(freq[s[right]]){
                    freq[s[left]]--;
                    left++;
                }
                freq[s[right]]++;
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};