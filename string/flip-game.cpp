class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        
        int n = currentState.size();
        vector<string> res;

        string s = currentState;

        for(int i=0; i<n-1; i++){
            if(s[i] == '+' && s[i+1] == '+'){
                s[i] = '-';
                s[i+1] = '-';
                res.push_back(s);
                s = currentState;
            }
        }

        return res;
    }
};