class Solution {
public:
    int longestPalindrome(string s) {
        
        int freq[52] = {0};

        for(char c : s){
            int index;
            if(c >= 'A' && c <= 'Z'){
                index = c - 'A';
            }else{
                index = c - 'a' + 26; 
            }
            freq[index]++;
        }
        
        int length = 0;
        bool odd = false;

        for(int count : freq){

            length += (count/2) * 2;

            if(count % 2 == 1){
                odd = true;
            }
        }

        return odd ? length + 1 : length;


        // unordered_map<char, int> freq;

        // for(char c : s){
        //     freq[c]++;
        // }

        // int length = 0;
        // int count = 0;
        // for(auto [c, inc] : freq){
        //     if(inc%2 ==1){
        //         count++;
        //     }
        //     if(inc >= 2){
        //         length += 2 * (inc/2);
        //     }
        // }

        // if(count > 0){
        //     length += 1;
        // }

        // return length;
    }
};