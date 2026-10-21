class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> freq;

        for(char c : magazine){
            freq[c]++;
        }


        for(int i=0; i<ransomNote.length(); i++){
            if(freq.find(ransomNote[i]) != freq.end() && freq[ransomNote[i]]!= 0){
                freq[ransomNote[i]]--;
            }else{
                return false;
            }
        }

        return true;
    }
};