class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.length();
        int left = 0;
        int maxLength = 0;
        unordered_map<char, int> freq;
        for(int i=0; i<n; i++){
            freq[s[i]]++;
            if(freq.size() > k){
                freq[s[left]]--;

                if(freq[s[left]] == 0){
                    freq.erase(s[left]);
                }
                left++;
            }
            maxLength = max(maxLength, i - left + 1);
        }
        return maxLength;
    }
};