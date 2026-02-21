class Solution {
//brute force
private:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c =='o' || c=='u')
            return true;
        return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> result;
        unordered_map<string, bool> voweledWords;
        for(auto& query : queries){
            int count = 0;
            int l = query[0];
            int r = query[1];
            for(int i = l; i<=r; i++){
                char first = words[i][0];
                char last  = words[i][words[i].size() - 1];
                if(voweledWords[words[i]]){
                    count++;
                    continue;
                }
                else if(isVowel(first) && isVowel(last)){
                    count++;
                    voweledWords[words[i]] = true;
                }
            }
            result.push_back(count);
        }
        return result;
    }
};