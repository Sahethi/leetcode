class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        unordered_map<char, int> freq;
        for(char c : text){
            freq[c]++;
        }
        int bCount = freq['b'];
        int aCount = freq['a'];
        int lCount = freq['l'] / 2;
        int oCount = freq['o'] / 2;
        int nCount = freq['n'];

        return min({bCount, aCount, lCount, oCount, nCount});
    }
};