class Solution {
public:
    bool canPermutePalindrome(string s) {
        
        unordered_map<char,int> freq;

        for(char c : s){
            freq[c]++;
        }
        
        int countOdd = 0, countEven = 0;

        for(auto &[c, f] : freq){
            if(f % 2 == 1){
                countOdd++;
            }
        }

        if(countOdd <= 1){
            return true;
        }

        return false;
    }
};