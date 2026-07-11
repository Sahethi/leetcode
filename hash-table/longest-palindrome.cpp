class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> freq;

        for(char c : s){
            freq[c]++;
        }

        int length = 0;
        int count = 0;
        for(auto [c, inc] : freq){
            if(inc == 1){
                count++;
            }
            if(inc >= 2){
                length += 2 * (inc/2);
            }
        }

        if(count > 0){
            length += 1;
        }

        return length;
    }
};