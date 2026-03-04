class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastSeen(26);

        for(int i=0; i<s.length(); i++){
            lastSeen[s[i] - 'a'] = i;
        }

        int start = 0, end = 0;
        vector<int> result;
        for(int i=0; i<s.length(); i++){
            end = max(end, lastSeen[s[i] - 'a']);
            if(i == end){
                result.push_back((end - start) + 1);
                start = i + 1;
            }
        }
        return result;
    }
};