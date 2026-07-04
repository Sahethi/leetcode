class Solution {
public:
    string reorganizeString(string s) {
        //so i think string cant be rearranged if for every 2 freq count u need 1 count
        /**

        if 2 -> atleast 1 unique char
        if 3 count -> atleast 2 unqie to break apart

        basically if the most frequeuct chr occurs n times then we need n-1 gaps to be filled
        **/   

        vector<int> freq(26,0);

        for(char c : s){
            freq[c-'a']++;
        }

        int maxCount = *max_element(freq.begin(), freq.end());
        int n = s.size();
        if(maxCount * 2 > n+1) return "";

        vector<pair<int, char>> chars;
        
        for(int i=0; i<26; i++){
            if(freq[i] > 0){
                chars.push_back({freq[i], char(i+'a')});
            }
        }

        sort(chars.begin(), chars.end(), greater<>());

        string ans(n, ' ');
        int idx = 0;

        for(auto& [count, c] : chars){
            while(count>0){
                ans[idx] = c;
                count--;

                idx += 2;

                if(idx >= n){
                    idx = 1;
                }
            }
        }

        return ans;

    }
};