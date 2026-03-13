class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> res = {""};
        unordered_map<char, string> map = {
            {'2', "abc"}, {'3', "def"},
            {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"},
        };
        string ans;
        for(char digit : digits){
            vector<string> temp;
            string letters = map[digit];
            for(string s : res){
                for(char letter : letters){
                    temp.push_back(s+letter);
                }
            }
            res = temp;
        }
        
        return res;




























        // if(digits.empty()) return {};

        // unordered_map<char, string> mp = {
        //     {'2', "abc"}, {'3', "def"},
        //     {'4', "ghi"}, {'5', "jkl"},
        //     {'6', "mno"}, {'7', "pqrs"},
        //     {'8', "tuv"}, {'9', "wxyz"}
        // };

        // vector<string> result = {""};

        // for(char digit : digits){
        //     vector<string> temp;
        //     string letters = mp[digit];
        //     for(string s : result)
        //         for(char letter : letters)
        //             temp.push_back(s + letter);
        //     result = temp;
        // }

        // return result;
    }
};