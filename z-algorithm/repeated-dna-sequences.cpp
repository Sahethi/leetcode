class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        unordered_map<string, int> freq;
        vector<string> result;

        for(int i=0; i<=n-10; i++){
            string window = s.substr(i, 10);
            freq[window]++;
        }

        for(auto& [window, f] : freq){
            if(f > 1){
                result.push_back(window);
            }
        }

        return result;
    }
};