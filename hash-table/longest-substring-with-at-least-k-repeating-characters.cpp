class Solution {
public:
/**
    int solve(string s, int k){
        if(s.length() < k) return 0;

        unordered_map<char, int> freq;

        for(int i=0; i<s.size(); i++){
            freq[s[i]]++;
        }
        for(int i=0; i<s.size(); i++){
            if(freq[s[i]] < k){
                int leftLen = solve(s.substr(0, i), k);
                int rightLen = solve(s.substr(i + 1), k);
                return max(leftLen, rightLen);
            }
        }

        return s.length();        
    }
    **/
    int longestSubstring(string s, int k) {
        // return solve(s, k); 
        int maxLength = 0;
        int n = s.size();
        for(int distinctLimit=1; distinctLimit<=26; distinctLimit++){
            int left = 0;
            int uniqueCount = 0;
            int countAtleastK = 0;
            unordered_map<char, int> freq;

            for(int right = 0; right<n; right++){
                freq[s[right]]++;

                if(freq[s[right]] == 1) uniqueCount++;

                if(freq[s[right]] == k) countAtleastK++;

                while(uniqueCount > distinctLimit){
                    freq[s[left]]--;

                    if(freq[s[left]] == k - 1){
                        countAtleastK--;
                    }

                    if(freq[s[left]] == 0){
                        uniqueCount--;
                        freq.erase(s[left]);
                    }
                    left++;
                }

                if(uniqueCount == countAtleastK){
                    maxLength = max(maxLength, right - left+1);
                }
            }
        }

        return maxLength;
    }
};