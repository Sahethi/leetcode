class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        unordered_map<char, int> freq;
        int left = 0;   
        int n = s.length();
        int maxLength = 0;

        for(int i=0; i<n; i++){
            freq[s[i]]++;
            // a - 3 b - 3 c - 1
            // crrently size is 3
            // 
            while(freq.size() > 2){
                
                freq[s[left]]--;
                if(freq[s[left]] == 0){
                    freq.erase(s[left]);
                }
                left++;
            }
            maxLength = max(maxLength, (i - left) + 1);
        }

        return maxLength;
    }
};