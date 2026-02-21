class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> count(26, 0);

        //creating a freq map for s1 chars
        for(char c : s1){
            count[c - 'a']++;
        }

        int left = 0;
        bool match = false;
        for(int right = 0; right < s2.size(); right++){
            count[s2[right] - 'a']--;

            if(right - left + 1 > s1.size()){
                count[s2[left] - 'a']++;
                left++;
            }

            if(right - left + 1 == s1.size()){
                match = true;
                for(int i=0; i<26; i++){
                    if(count[i] != 0){
                        match = false;
                        break;
                    }
                }
                if(match) return true;
            }
        }
        
        return false;
    }
};