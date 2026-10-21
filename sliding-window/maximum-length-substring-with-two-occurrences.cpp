class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26, 0);
        int ptr1 = 0, ptr2 = 0;
        int maxLenSubstr = 0;
        int n = s.size();
        while (ptr2 < n) {
            freq[s[ptr2] - 'a']++;
            while (ptr1 < ptr2 && freq[s[ptr2] - 'a'] > 2) {
                freq[s[ptr1] - 'a']--;
                ptr1++;
            }
            maxLenSubstr = max(maxLenSubstr, ptr2 - ptr1 + 1);
            ptr2++;
        }

        return maxLenSubstr;
    }
};