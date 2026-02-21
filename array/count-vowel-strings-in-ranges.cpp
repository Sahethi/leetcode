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
        vector<int> validArr;
        vector<int> prefix;
        for(int i=0; i<words.size(); i++){
            char first = words[i][0];
            char last  = words[i][words[i].size() - 1];
            if(isVowel(first) && isVowel(last)){
                validArr.push_back(1);
            }else{
                validArr.push_back(0);
            }
        }
        int sum = 0;
        for(int i=0; i<validArr.size(); i++){
             sum += validArr[i];
             prefix.push_back(sum);
        }

        for(auto& query : queries){
            int count = 0;
            int l = query[0];
            int r = query[1];
            if(l == 0)
                count = prefix[r];
            else count = prefix[r] - prefix[l-1];
            result.push_back(count);
        }
        return result;
    }
};