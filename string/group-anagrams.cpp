class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for(string s : strs){
            string t = s;
            sort(t.begin(), t.end());

            map[t].push_back(s);
        }

        vector<vector<string>> result;
        for(auto it = map.begin(); it != map.end(); it++){
            result.push_back(it->second);
        }
        return result;
    }
};